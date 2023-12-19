use peekmore::PeekMore;
use verifier::Verifier;

mod inst;
mod verifier;

#[no_mangle]
pub extern "C" fn lfi_verify_bytes(raw_bytes: *const u8, size: usize) -> bool {
    let bytes = unsafe { std::slice::from_raw_parts(raw_bytes, size) };

    let mut verif = Verifier {
        failed: false,
        msg: String::new(),
    };

    let mut iter = bad64::disasm(bytes, 0).peekmore();
    while let Some(maybe_decoded) = iter.next() {
        match maybe_decoded {
            Ok(inst) => {
                verif.check_insn(&inst, &mut iter);
            }
            Err(_) => return false,
        }
    }

    return !verif.failed;
}
