#!/usr/bin/python3

import argparse
import bisect
from collections import Counter, defaultdict
from configparser import ConfigParser
from dataclasses import dataclass
import itertools
import re
from typing import Any, NamedTuple

BITS_SUBGRP = 7
BITS_SUBTRIE = 9
GRP_START = 1 << (BITS_SUBTRIE - BITS_SUBGRP)
MAX_SUBGRPS = 1 << BITS_SUBGRP
MAX_SUBTRIES = (1 << BITS_SUBTRIE) - 1
MAX_GRPS = (1 << (16 - BITS_SUBGRP)) - GRP_START

print_decode_trie = False

class ParseException(Exception):
    def __init__(self, message, str, col):
        super().__init__(message)
        self.str = str
        self.col = col

class MaskedVal(NamedTuple):
    val: int
    mask: int

    def __rshift__(self, other: int):
        if type(other) != int:
            return NotImplemented
        return MaskedVal(self.val >> other, self.mask >> other)
    def __and__(self, other):
        if type(other) == int:
            return MaskedVal(self.val & other, self.mask & other)
        return NotImplemented

def bitmaskrange(fixed: MaskedVal, max: int):
    idx = fixed.mask
    while idx < max:
        yield (idx & ~fixed.mask) | fixed.val
        idx = (idx + 1) | fixed.mask

class DescEntry(NamedTuple):
    idx: int
    size: int
    fixed: MaskedVal
    name: str|None = None
    flags: str = ""

Desc = list[DescEntry]

def parse_desc(desc: str) -> Desc:
    res = []
    idx = 0
    remainder = desc
    while remainder:
        m = re.match(r'([01]+)|{(\d+):([a-zA-Z0-9|]+)(?:=([01x]+))?}', remainder)
        if not m or (m[4] and len(m[4]) != int(m[2])):
            raise ParseException(f"invalid syntax", desc, len(desc)-len(remainder))

        bits = m[1] or m[4] or "x" * int(m[2])
        mask = int(bits.translate(str.maketrans("01x", "110")), 2)
        val = int(bits.translate(str.maketrans("01x", "010")), 2)
        fixed = MaskedVal(val, mask)
        name, _, flags = m[3].partition("|") if m[3] else (None, None, "")
        res.append(DescEntry(32-idx-len(bits), len(bits), fixed, name, flags))

        remainder = remainder[len(m[0]):]
        idx += res[-1].size
    if idx != 32:
        raise ParseException(f"descriptor contains {idx} bits, not 32", desc, 0)
    return res

RE_FMT = re.compile(r'([^{]+)' +
                    r'|{(\w+(?:<\d+(?::\d+)?>)?(?:,\w+(?:<\d+(?::\d+)?>)?)*)((?::\^?[^,=:}]+(?:,[^,=:}]+)*=[^:}]*|:![^,=:}]+(?:,[^,=:}]+)*)+)}')

RE_FMT_VAR = re.compile(r'^(\w+)(?:<(\d+)(?::(\d+))?>)?$')

class Fmt:
    def __init__(self, fmt: str, desc: Desc):
        self.desc = desc
        self.comps = []

        varmap = {e.name: i for i, e in enumerate(desc)}
        def parse_var(var: str) -> tuple[int, int]: # shift, sz
            var_comps = RE_FMT_VAR.match(var)
            if var_comps is None:
                raise Exception(f"couldn't match variable {var}")
            de = desc[varmap[var_comps[1]]]
            if var_comps[2]:
                high = int(var_comps[2])
                low = int(var_comps[3]) if var_comps[3] else high
                return de.idx + low, high - low + 1
            return de.idx, de.size

        while fmt:
            m = RE_FMT.match(fmt)
            if not m:
                raise ParseException(f"invalid format {fmt}", fmt, 0)
            if m[1]:
                self.comps.append(m[1])
            else:
                vars = [parse_var(var) for var in m[2].split(",")]
                masks = [(1 << sz) - 1 << shift for shift, sz in vars]
                assert sum(masks).bit_count() == sum(m.bit_count() for m in masks)
                d = {}
                for vals, _, text in (x.partition("=") for x in m[3][1:].split(":")):
                    negate, overwrite = vals[:1] == "!", vals[:1] == "^"
                    vals = vals[negate or overwrite:]
                    numvals: list[list[int]] = []
                    for val, (shift, sz) in zip(vals.split(","), vars):
                        if val == "*":
                            numvals.append(list(range(0, 1 << shift+sz, 1 << shift)))
                        else:
                            assert 0 <= int(val, 0) < (1 << sz)
                            numvals.append([int(val, 0) << shift])
                    assert len(numvals) == len(vars)
                    for k in itertools.product(*numvals):
                        if negate:
                            del d[sum(k)]
                        else:
                            assert (sum(k) in d) == overwrite
                            d[sum(k)] = text
                self.comps.append((sum(masks), d))
            fmt = fmt[len(m[0]):]

    def eval(self, descvals: list[MaskedVal]) -> str|None:
        # For given values, return the unique string the format evaluates to.
        res = ""
        for comp in self.comps:
            if type(comp) == str:
                res += comp
            elif type(comp) == tuple:
                # Performance optimization, both cases behave are identical.
                if len(descvals) == 1 and descvals[0].mask & comp[0] == comp[0]:
                    results = [comp[1].get(descvals[0].val & comp[0])]
                else:
                    results = list({comp[1].get(k) for v in descvals
                        for k in bitmaskrange(v & comp[0], comp[0] + 1)})
                    if len(results) != 1:
                        raise Exception(f"unable to specialize format {self}, candidates are {results}")
                if results[0] is None:
                    return None
                res += results[0]
        return res

    def expansions(self) -> dict[str, list[MaskedVal]]:
        # Return a dict mapping expansions to all possible values for this.
        specmsk = 0
        for comp in self.comps:
            if type(comp) == tuple:
                specmsk |= comp[0]
        baseval = sum(de.fixed.val << de.idx for de in self.desc)
        basemsk = sum(de.fixed.mask << de.idx for de in self.desc) | specmsk
        derivs: dict[str, list[MaskedVal]] = defaultdict(list)
        for prod in bitmaskrange(MaskedVal(baseval, specmsk ^ 0xffffffff), 1 << 32):
            if name := self.eval([mask := MaskedVal(prod, basemsk)]):
                derivs[name].append(mask)

        return dict(derivs)

class TrieDesc(NamedTuple):
    fixed: MaskedVal
    subgrp: int
    name: str = ""
    cond: str|None = None

class Trie(NamedTuple):
    fmsk: int
    fval: int
    smsk_start: int
    smsk_len: int
    table: tuple[int, ...]
    subtries: tuple[Any, ...] # Any is actually Trie
    comment: str

    @property
    def table_size(self):
        return len(self.table) + sum(st.table_size for st in self.subtries)

    def codegen(self, fn_prefix: str, tables_as_switch: bool) -> str:
        stnames = [f"{fn_prefix}_{i+1:x}" for i in range(len(self.subtries))]
        res = "\n".join(st.codegen(n, tables_as_switch) for st, n in zip(self.subtries, stnames))
        res += f"\n// {self.comment}"
        res += f"\nstatic unsigned {fn_prefix}(uint32_t inst) {{\n"
        if self.fmsk:
            res += f"  if ((inst&{self.fmsk:#x}) != {self.fval:#x}) return 0;\n"
        if not self.subtries and len(set(self.table)) == 1:
            res += f"  return {hex(self.table[0])};\n"
            res += "}\n"
            return res
        table_idx = f"(inst >> {self.smsk_start}) & {(1<<self.smsk_len)-1:#x}"
        if tables_as_switch:
            res += f"  unsigned idx;\n"
            res += f"  switch ({table_idx}) {{\n"
            for i, t in enumerate(self.table):
                res += f"    case {i:#x}: idx = {t:#x}; break;\n"
            res += "  }\n"
        else:
            res += "  static const uint16_t table[] = {\n"
            res += "    " + ",".join(f"{t:#x}" for t in self.table) + " };\n"
            res += f"  unsigned idx = table[{table_idx}];\n"
        if self.subtries:
            res += "  switch (idx) {\n"
            for i in range(len(self.subtries)):
                res += f"    case {i+1:#x}: return {stnames[i]}(inst);"
                res += f" // {self.subtries[i].comment}\n"
            res += "  }\n"
        res += "  return idx;\n"
        res += "}\n"
        return res

def make_table(descs: list[TrieDesc], for_keys, prev_msk=0):
    cnts: list[list[int]] = [[0, 0] for _ in range(32)]
    kmsks = 0xffffffff
    for k in for_keys:
        km = descs[k].fixed
        kmsks &= km.mask
        for i, l in enumerate(cnts):
            if (km.mask&~prev_msk) & (1<<i):
                l[km.val & (1<<i) != 0] += 1

    # There is the case that bits end up being cleared in km.mask/kmsks without
    # actually distinguishing different encodings (e.g., due to constraints).
    # TODO: eliminate these.

    fmsk = kmsks & sum(1<<i for i, cnt in enumerate(cnts) if 0 in cnt and sum(cnt) > 0)
    fval = fmsk & sum((cnt[0] == 0) << i for i, cnt in enumerate(cnts))
    debug_keys = ",".join(descs[k].name for k in for_keys) if prev_msk else "*"
    if print_decode_trie:
        indent = " " * bin(prev_msk).count("1") + ">"
        print(indent, debug_keys, f"filter={fmsk:032b}:{fval:032b}", {i: cnt for i, cnt in enumerate(cnts) if sum(cnt)})
    if all(0 in cnt for cnt in cnts):
        # only one entry left
        if len(for_keys) != 1:
            raise Exception(f"redundant opcodes: {for_keys} ({debug_keys})")
        return Trie(fmsk, fval, 0, 0, (descs[next(iter(for_keys))].subgrp,), (), debug_keys)

    # Compute mask over first streak of differing bits
    smsk_end = next(32-i for i, cnt in enumerate(cnts[::-1]) if 0 not in cnt)
    smsk_len = next((i for i, cnt in enumerate(cnts[smsk_end-1::-1]) if 0 in cnt), smsk_end)
    smsk_len = min(12, smsk_len)
    smsk_start = smsk_end - smsk_len
    smsk = ((1 << smsk_len) - 1) << smsk_start
    if print_decode_trie:
        print(indent, smsk_start, smsk_len, f"smsk={smsk:032b}")

    table_keys: list[list[int]] = [[] for _ in range(1 << smsk_len)]
    for k in for_keys:
        for idx in bitmaskrange((descs[k].fixed & smsk) >> smsk_start, 1 << smsk_len):
            table_keys[idx].append(k)

    table = [0 for _ in range(1 << smsk_len)]
    subtries = []
    subtrie_map = {}
    for i, keys in enumerate(table_keys):
        if not keys:
            continue
        if len(keys) == 1 and descs[keys[0]].fixed.mask&~(prev_msk|fmsk|smsk) == 0:
            table[i] = descs[keys[0]].subgrp
        else:
            keys_set = frozenset(keys)
            assert len(keys_set) == len(keys)
            if keys_set not in subtrie_map:
                subtrie = make_table(descs, keys, prev_msk|fmsk|smsk)
                if not subtrie.fmsk and len(set(subtrie.table)) == 1:
                    subtrie_map[keys_set] = subtrie.table[0]
                else:
                    subtries.append(subtrie)
                    subtrie_map[keys_set] = len(subtries)
            table[i] = subtrie_map[keys_set]

    if len(subtries) > MAX_SUBTRIES:
        print(len(subtries), ">", MAX_SUBTRIES, subtries)
        raise Exception(f"too many subtries: {len(subtries)} > {MAX_SUBTRIES}")
    return Trie(fmsk, fval, smsk_start, smsk_len, tuple(table), tuple(subtries), debug_keys)

# From Fadec
def superstring(strs):
    # This faces the "shortest superstring" problem, which is NP-hard.
    # Preprocessing: remove any strings which are already completely covered
    realstrs = []
    for s in sorted(strs, key=len, reverse=True):
        for s2 in realstrs:
            if s in s2:
                break
        else:
            realstrs.append(s)

    # Greedy heuristic generally yields acceptable results, though it depends on
    # the order of the menmonics. More compact results are possible, but the
    # expectable gains of an optimal result (probably with O(n!)) are small.
    # First sort strings and later do a binary search for each possible prefix.
    realstrs.sort()
    merged = ""
    while realstrs:
        for i in range(min(16, len(merged)), 0, -1):
            idx = bisect.bisect_left(realstrs, merged[-i:])
            if idx < len(realstrs) and realstrs[idx][:i] == merged[-i:]:
                merged += realstrs.pop(idx)[i:]
                break
        else:
            merged += realstrs.pop()
    return merged

def check_feature(features, featurestr):
    return all(features[x] for x in featurestr.split("&&"))

class DecoderGenerator:
    mnems: dict[str, int] = {}
    grpnums: dict[str, int] = {}
    trie_descs: list[TrieDesc] = []
    decstr: dict[int, str] = {}
    decoders: dict[int, str] = {}
    docs: dict[str, dict[str, tuple[Desc, Fmt]]] = {}

    @staticmethod
    def generate_opdecoder(decodestr: str, desc: Desc) -> str:
        res = "{"
        ops = set(x[1:] for x in re.findall(r'@[a-zA-Z0-9_]+', decodestr))
        for de in desc:
            if de.name in ops:
                ty = "int64_t" if de.flags == "s" else "uint64_t"
                if de.fixed.mask == (1 << de.size) - 1:
                    val = f"{de.fixed.val}"
                else:
                    val = f"inst>>{de.idx}&{(1<<de.size)-1:#x}"
                if de.flags == "s":
                    val = f"sext({val}, {de.size})"
                res += f"{ty} {de.name} = {val}; "
        # Split decodestr, respecting parenthesized operands.
        operands, parendepth = [], 0
        for comp in decodestr.replace("@", "").strip().split():
            if parendepth:
                operands[-1] += " " + comp
            else:
                operands.append(comp)
            parendepth += comp.count("(") - comp.count(")")
        for i, op in enumerate(operands):
            res += f"ddi->ops[{i}] = {op.rstrip(',')}; "
        return res + "break;}"

    def add_group(self, grp: str, grpdesc: Desc, props, features: dict[str, bool]):
        if grp in self.grpnums:
            raise Exception(f"redundant group {grp}")
        grpnum = self.grpnums[grp] = len(self.grpnums) + GRP_START

        if "decode" not in props:
            print(f"group {grp} without decode")
            return

        decodefmt = Fmt(props["decode"], grpdesc)
        featfmt = Fmt(props.get("feat", ""), grpdesc)
        derivs = Fmt(props["mnem"], grpdesc).expansions()
        assert len(derivs) <= MAX_SUBGRPS

        # Most mnems share the same decode operands, map opdecoder to mnems
        opdecoders = defaultdict(list)
        for i, (name, masks) in enumerate(derivs.items()):
            if name in self.mnems:
                raise Exception(f"redundant mnem {name}")
            mnem = self.mnems[name] = (grpnum << BITS_SUBGRP) + i

            # Ensure that every mnemonic is tied to one feature (i.e., when
            # adding a feature, an existing mnemonic won't get additional
            # semantics). Mnemonic values are added nonetheless so that code
            # can use the mnemonics even when they are disabled.
            if not check_feature(features, featfmt.eval(masks)):
                continue
            for j, mask in enumerate(masks):
                self.trie_descs.append(TrieDesc(mask, mnem, f"{grp}-{name}#{j}"))

            decmnem, _, opstr = decodefmt.eval(masks).partition(" ")
            self.decstr[mnem] = decmnem.replace("_", " ")
            # TODO: maybe specialize decoder on fixed values?
            opdecoders[self.generate_opdecoder(opstr, grpdesc)].append(name)

        if len(opdecoders) == 1:
            self.decoders[grp] = next(iter(opdecoders))
        else:
            switch = "switch (mnem) { default: __builtin_unreachable();\n"
            for opdecoder, mnems in opdecoders.items():
                switch += "  " + " ".join(f"case DA64I_{mnem}:" for mnem in mnems)
                switch += "\n    " + opdecoder + "\n"
            self.decoders[grp] = switch + "} break;"

    def generate(self, tables_as_switch) -> tuple[str, dict[str, str]]:
        trie = make_table(self.trie_descs, list(range(len(self.trie_descs))))
        mnems_strs = [f"DA64I_{k}={v:#x},\n" for k, v in self.mnems.items()]
        grpnum_strs = [f"DA64G_{k}={v:#x},\n" for k, v in self.grpnums.items()]
        decodestr = superstring(self.decstr.values())
        decstrtab = [f'[{m}] = {len(s) << 12 | decodestr.index(s):#x},\n'
            for m, s in self.decstr.items()]
        decoder = [f'case DA64G_{m}: {s}\n' for m, s in self.decoders.items()]
        public = f"""
enum Da64InstKind {{
  DA64I_UNKNOWN=0,
  {"".join(mnems_strs)}
}};
enum Da64InstGroup {{
  DA64G_UNKNOWN=0,
  {"".join(grpnum_strs)}
}};
#define DA64_GROUP(mnem) ((mnem) >> {BITS_SUBGRP})
"""

        return public, {
            "DA64_CLASSIFIER": trie.codegen("da64_classify_impl", tables_as_switch),
            "DA64_DECSTR": '"' + decodestr + '"',
            "DA64_DECSTRTAB": "".join(decstrtab),
            "DA64_DECODER": "".join(decoder),
        }

@dataclass
class EncodeFunc:
    paramtys: tuple[str, ...]
    expansions: tuple[str, ...]
    singleExpansion: bool = False
    allowOverride: bool = False
    cond: str|None = None

ENC_FUNCS = {
    "const": EncodeFunc((), ("{val}",)),
    "bool": EncodeFunc(("bool",), ("!!{0}",)),
    "regzr": EncodeFunc((), ("31",)),
    "reggp": EncodeFunc(("DA_GRegZR",), ("DA_REGVAL({0})",)),
    "reggpsp": EncodeFunc(("DA_GRegSP",), ("DA_REGVAL({0})",)),
    "reggpnozr": EncodeFunc(("DA_GReg",), ("DA_REGVAL({0})",)),
    "reggpls64": EncodeFunc(("DA_GReg",), ("DA_REGVAL({0})",), cond="DA_REGVAL({0})<24&&!(DA_REGVAL({0})&1)"),
    "regfp": EncodeFunc(("DA_VReg",), ("DA_REGVAL({0})",)),
    "regfplim": EncodeFunc(("DA_VReg",), ("DA_REGVAL({0})<<16",), singleExpansion=True, cond="DA_REGVAL({0})<{max}"),
    "prfop": EncodeFunc(("enum Da64PrfOp  prfop",), ("{0}&31",)),
    "cond": EncodeFunc(("Da64Cond",), ("{0}",)),
    "invcond": EncodeFunc(("Da64Cond",), ("({0}^1)",)),
    "imm": EncodeFunc(("unsigned",), ("{0}",), cond="{0}<{max}"),
    "immadr": EncodeFunc(("uintptr_t  codeaddr", "uintptr_t  target"), ("({1}-{0})&3", "(({1}-{0})>>2)&0x7ffff"), cond="da_sext(({1}-{0}),21)==(intptr_t)({1}-{0})"),
    "immadrp": EncodeFunc(
        ("uintptr_t  codeaddr", "uintptr_t  target"),
        ("((({1}&~0xfffull)-({0}&~0xfffull))>>12)&3", "((({1}&~0xfffull)-({0}&~0xfffull))>>14)&0x7ffff"),
        cond="da_sext(({1}&~0xfffull)-({0}&~0xfffull),33)==(intptr_t)(({1}&~0xfffull)-({0}&~0xfffull))",
    ),
    "immlsl": EncodeFunc(("unsigned  lsl",), ("(-{0})&({max}-1)", "{max}-1-{0}"), cond="{0}<{max}"),
    "immbfx": EncodeFunc(("unsigned  lsb", "unsigned  width"), ("{0}", "{0}+{1}-1"), cond="{0}<{max}&&{1}-1<{max}-{0}"),
    "immbfi": EncodeFunc(("unsigned  lsb", "unsigned  width"), ("(-{0})&({max}-1)", "{1}-1"), cond="{0}<{max}&&{1}-1<{max}-{0}"),
    # only base-imm instead of 2*base - imm, as relevant bit is already set.
    "immshiftr": EncodeFunc(("unsigned  imm",), ("({base}-{0})<<16",), singleExpansion=True, cond="{0}&&{0}<={base}"),
    "immshiftl": EncodeFunc(("unsigned  imm",), ("{0}<<16",), singleExpansion=True, cond="{0}&&{0}<={base}"),
    "immldraut": EncodeFunc(("int64_t",), ("({0}>>12)&1", "({0}&0xff8)>>3"), cond="da_sext({0},13)=={0}&&({0}&7)==0"),
    "immvidx": EncodeFunc(("unsigned",), ("{0}<<({size}+{shift})",), cond="{0}<(1u<<(4-{size}))", allowOverride=True),
    "immrotmul": EncodeFunc(("unsigned",), ("{0}/90",), cond="{0}<360&&{0}%90==0"),
    "immrotadd": EncodeFunc(("unsigned",), ("{0}/90-1",), cond="{0}==90||{0}==270"),
    "velemidx": EncodeFunc(("unsigned  elemidx",), ("({0}<<{size})>>3", "({0}<<{size})>>2", "({0}<<{size})>>1"), cond="{0}<(1u<<(4-{size}))", allowOverride=True),
    "velemidxlim": EncodeFunc(("unsigned  elemidx",), ("({0}<<{size})>>3", "({0}<<{size})>>2", "({0}<<{size})>>1"), cond="{0}<(1u<<(4-{size}))&&{0}<{lim}", allowOverride=True),
    "velemidx0": EncodeFunc(("unsigned  elemidx",), ("({0}<<{size})>>3", "({0}<<{size})>>2", "({0}<<{size})>>1", "(({0}<<{size})&1)<<3"), cond="{0}<(1u<<(4-{size}))", allowOverride=True),
    "memsimdidx": EncodeFunc(("unsigned  elemidx",), ("({0}<<{size})>>3", "({0}<<{size})>>2", "{0}<<{size}"), cond="{0}<(1u<<(4-{size}))", allowOverride=True),
    "uimm": EncodeFunc(("uint64_t",), ("{0}>>{lsr}",), cond="({0}&(((1<<{bits})-1)<<{lsr}))=={0}"),
    "simm": EncodeFunc(("int64_t",), ("{0}/(1<<{asr})",), cond="da_sext({0},{bits}+{asr})=={0}&&({0}&((1<<{asr})-1))==0"),
    "tbz": EncodeFunc(("unsigned  bit",), ("{0}>>5", "{0}&0x1f"), cond="{0}<64"),
    "reladdr": EncodeFunc(("ptrdiff_t",), ("{0}",), cond="da_sext({0},{bits})=={0}"),
    "fcvtfixscale": EncodeFunc(("unsigned  fbits",), ("64-{0}",), cond="{0}<{max}"),
    "immadd": EncodeFunc(("int{size}_t  imm",), ("da_immadd({0})",), singleExpansion=True, cond="da_immadd({0}) != 0xffffffff"),
    "immlogical": EncodeFunc(("uint{size}_t  imm",), ("da_immlogical({0}, {size}>>6)",), singleExpansion=True, cond="da_immlogical({0}, {size}>>6) != 0xffffffff"),
    "immfmov32": EncodeFunc(("float  imm",), ("da_immfmov32({0})",), cond="da_immfmov32({0}) != 0xffffffff"),
    "immfmov64": EncodeFunc(("double  imm",), ("da_immfmov64({0})",), cond="da_immfmov64({0}) != 0xffffffff"),
    "immsimd8movi": EncodeFunc(("uint64_t  imm64",), ("da_immsimdmovi({0})",), singleExpansion=True, cond="da_immsimdmovi({0}) != 0xffffffff"),
    "immsimd8lsl": EncodeFunc(("uint8_t  imm", "unsigned  lsl"), ("{0}>>5", "{0}&0x1f", "{1}>>2|1"), cond="{1}<(8*{maxshift}) && ({1}&7) == 0"),
    "immsimd8fmov": EncodeFunc(("float  imm",), ("da_immfmov32({0})>>5", "da_immfmov32({0})&0x1f"), cond="da_immfmov32({0}) != 0xffffffff"),
}

class EncoderGenerator:
    decls: list[str] = []
    defns: list[str] = []
    encode_in_header = False

    def __init__(self, encode_in_header=False):
        self.encode_in_header = encode_in_header

    def add_group(self, grp: str, grpdesc: Desc, props, features: dict[str, bool]):
        featfmt = Fmt(props.get("feat", ""), grpdesc)
        for key in props:
            if key.startswith("encmnem"):
                cat = key[7:]
                mnemfmt = Fmt(props[f"encmnem{cat}"], grpdesc)
                opsfmt = Fmt(props[f"encops{cat}"], grpdesc)
                condfmt = Fmt(props.get(f"enccond{cat}", ""), grpdesc)
                featfmt = Fmt(props.get(f"encfeat{cat}", props.get("feat", "")), grpdesc)
                derivs = mnemfmt.expansions()
                for name, masks in derivs.items():
                    assert len(masks) == 1, "encmnem with multiple descs per name"
                    ops = opsfmt.eval(masks)
                    cond = condfmt.eval(masks)
                    if not check_feature(features, featfmt.eval(masks)):
                        continue
                    self.add_mnem(grp, name, grpdesc, masks[0], ops, cond)

    def add_mnem(self, grp: str, name: str, grpdesc: Desc, descmask: MaskedVal, ops: str, cond: str):
        paramtys: list[str] = []
        parnames: list[str] = []
        conds: list[str] = []
        assignments: dict[str, str] = {}
        grandExpansions: list[str] = []
        varaliases: dict[str, str] = {}
        for varstr, _, funcspec in (comp.partition("=") for comp in ops.split()):
            vars = varstr.split(",")
            if funcspec[0] == "@":
                aliases = funcspec[1:].split(",")
                assert len(vars) == len(aliases), "var alias mismatch"
                for var, alias in zip(vars, aliases):
                    varaliases[var] = alias
                continue

            funcname, _, funcops = funcspec.partition("/")
            funcops = [op.partition("=") for op in funcops.split(",")]
            funcops = {key: val for key, _, val in funcops if key}
            func = ENC_FUNCS[funcname]
            parnamebase = "".join(vars)
            funcparnames = []
            for ty, _, parname in (ty.partition("  ") for ty in func.paramtys):
                funcparnames.append(parname or parnamebase)
                paramtys.append(ty.format(**funcops))
            parnames += funcparnames
            if func.cond:
                conds.append(func.cond.format(*funcparnames, **funcops))

            if func.singleExpansion:
                assert len(func.expansions) == 1
                grandExpansions.append(func.expansions[0].format(*funcparnames, **funcops))
                for var in vars:
                    assignments[var] = "0"
                continue

            assert len(vars) == len(func.expansions)
            for var, expansion in zip(vars, func.expansions):
                if var in assignments and not func.allowOverride:
                    raise Exception(f"duplicate assignment to {var}")
                assignments[var] = expansion.format(*funcparnames, **funcops)

        for alias, var in varaliases.items():
            assignments[alias] = assignments[var]

        if cond:
            getval = lambda m: f"({assignments[m.group(1)]})"
            conds.append(re.sub(r'@([a-zA-Z0-9_]+)', getval, cond))

        # use XOR s.t. immadd can toggle between add and sub.
        buildexprs = ["(" + "^".join([f"{descmask.val:#x}"] + grandExpansions) + ")"]
        for de in grpdesc:
            bitmask = ((1 << de.size) - 1) << de.idx
            if de.name in assignments:
                buildexprs.append(f"(({assignments[de.name]})<<{de.idx}&{bitmask:#x})")
            elif descmask.mask & bitmask != bitmask:
                print("Encode desc missing for", grp, name, de.name, assignments)
                return
        expr = "|".join(buildexprs)
        if conds:
            condexpr = "&&".join(f"({cond})" for cond in conds)
            expr = f"!({condexpr}) ? 0 : {expr}"

        substs = {"DA_GRegSP": "DA_GPSP", "DA_GRegZR": "DA_GPZR"}
        if any(ty in substs for ty in paramtys):
            implname = f"de64_impl_{name}"
            macroparams = ",".join(parnames)
            macroargs = ",".join(f"{substs.get(ty, '')}({parname})" for ty, parname in zip(paramtys, parnames))
            self.decls.append(f"#define de64_{name}({macroparams}) {implname}({macroargs})")
        else:
            implname = f"de64_{name}"
        paramstr = ", ".join(f"{ty} {parname}" for ty, parname in zip(paramtys, parnames))
        if not paramstr:
            paramstr = "void"
        signature = f"uint32_t {implname}({paramstr})"
        if self.encode_in_header:
            self.decls.append(f"static inline {signature} {{ return {expr}; }}")
        else:
            self.decls.append(signature + ";")
            self.defns.append(f"{signature} {{ return {expr}; }}")

    def generate(self) -> tuple[str, dict[str, str]]:
        return "\n".join(self.decls) + "\n", {
            "DA64_ENCODER": "\n".join(self.defns),
        }

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--features")
    parser.add_argument("--coverage", action="store_true",
        help="Generate decode tables as switch for measuring coverage")
    parser.add_argument("--encode-in-header", action="store_true",
        help="Move most encoding logic to header")
    parser.add_argument("--feature-desc", help="Feature description file")
    parser.add_argument("out_public", type=argparse.FileType("w"))
    parser.add_argument("out_private", type=argparse.FileType("w"))
    parser.add_argument("descfiles", nargs="+")
    args = parser.parse_args()

    features = {"": True}
    if args.feature_desc:
        featuredesc = ConfigParser(interpolation=None, delimiters=(":",), strict=True)
        featuredesc.optionxform = str # make keys case-sensitive
        with open(args.feature_desc, "r") as f:
            featuredesc.read_file(f)
        attrset = defaultdict(set)
        for feature in featuredesc.sections():
            features[feature] = False
            attrset[feature.lower()].add(feature)
            if "avail" in featuredesc[feature]:
                attrset[featuredesc[feature]["avail"]].add(feature)
            if "incomplete" not in featuredesc[feature]:
                attrset["all"].add(feature)
        for i in range(1, 10):
            attrset[f"armv8.{i}a"] |= attrset[f"armv8.{i-1}a"]
        for i in range(0, 5):
            attrset[f"armv9.{i}a"] |= attrset[f"armv8.{i+5}a"]
        for i in range(1, 5):
            attrset[f"armv9.{i}a"] |= attrset[f"armv9.{i-1}a"]
        attrset["really-all"] = set(features.keys())

        for attr in (args.features or "all").strip().split(","):
            if attrs := attrset.get(attr):
                for attr in attrs:
                    features[attr] = True
            else:
                raise Exception(f"unknown feature {attr}")

    config = ConfigParser(interpolation=None, delimiters=(":",), strict=True)
    config.optionxform = str # make keys case-sensitive
    for descfile in args.descfiles:
        with open(descfile, "r") as f:
            config.read_file(f)

    decoder = DecoderGenerator()
    encoder = EncoderGenerator(args.encode_in_header)
    for grp in config.sections():
        try:
            props = config[grp]
            grpdesc = parse_desc(props["desc"])

            decoder.add_group(grp, grpdesc, props, features)
            encoder.add_group(grp, grpdesc, props, features)
        except ParseException as e:
            print("error parsing", grp, e)
            raise

    public_features = "".join(f"#define DA64_HAVE_{f} {n:d}\n" for f, n in features.items())
    public_decode, private_decode = decoder.generate(tables_as_switch=args.coverage)
    public_encode, private_encode = encoder.generate()
    private_dict = dict(private_decode, **private_encode)
    private_str = "".join(f"#{'el' if i else ''}if defined({key})\n{val}\n"
                          for i, (key, val) in enumerate(private_dict.items()))
    private_str += '#else\n#error "unknown table"\n#endif\n'

    args.out_public.write(public_features + public_decode + public_encode)
    args.out_private.write(private_str)
