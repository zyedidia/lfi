#include <array>
#include <cstdint>
#include <cstring>
#include <mcl/assert.hpp>
#include <iostream>
#include "dynarmic.h"
#include "dynarmic/interface/A64/a64.h"
#include "dynarmic/interface/A64/config.h"
#include "dynarmic/interface/exclusive_monitor.h"

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using Vector = Dynarmic::A64::Vector;

class A64FastmemTestEnv final : public Dynarmic::A64::UserCallbacks {
public:
    u64 ticks_left = 0;
    char* backing_memory = nullptr;
    Dynarmic::A64::Jit* jit;

    explicit A64FastmemTestEnv(char* addr) : backing_memory(addr) {}

    template<typename T>
    T read(u64 vaddr) {
        T value;
        memcpy(&value, backing_memory + vaddr, sizeof(T));
        return value;
    }
    template<typename T>
    void write(u64 vaddr, const T& value) {
        memcpy(backing_memory + vaddr, &value, sizeof(T));
    }

    std::optional<std::uint32_t> MemoryReadCode(u64 vaddr) override {
        uint32_t result = read<std::uint32_t>(vaddr);
        return result;
    }

    std::uint8_t MemoryRead8(u64 vaddr) override {
        return read<std::uint8_t>(vaddr);
    }
    std::uint16_t MemoryRead16(u64 vaddr) override {
        return read<std::uint16_t>(vaddr);
    }
    std::uint32_t MemoryRead32(u64 vaddr) override {
        return read<std::uint32_t>(vaddr);
    }
    std::uint64_t MemoryRead64(u64 vaddr) override {
        return read<std::uint64_t>(vaddr);
    }
    Vector MemoryRead128(u64 vaddr) override {
        return read<Vector>(vaddr);
    }

    void MemoryWrite8(u64 vaddr, std::uint8_t value) override {
        write(vaddr, value);
    }
    void MemoryWrite16(u64 vaddr, std::uint16_t value) override {
        write(vaddr, value);
    }
    void MemoryWrite32(u64 vaddr, std::uint32_t value) override {
        write(vaddr, value);
    }
    void MemoryWrite64(u64 vaddr, std::uint64_t value) override {
        write(vaddr, value);
    }
    void MemoryWrite128(u64 vaddr, Vector value) override {
        write(vaddr, value);
    }

    bool MemoryWriteExclusive8(u64 vaddr, std::uint8_t value, [[maybe_unused]] std::uint8_t expected) override {
        MemoryWrite8(vaddr, value);
        return true;
    }
    bool MemoryWriteExclusive16(u64 vaddr, std::uint16_t value, [[maybe_unused]] std::uint16_t expected) override {
        MemoryWrite16(vaddr, value);
        return true;
    }
    bool MemoryWriteExclusive32(u64 vaddr, std::uint32_t value, [[maybe_unused]] std::uint32_t expected) override {
        MemoryWrite32(vaddr, value);
        return true;
    }
    bool MemoryWriteExclusive64(u64 vaddr, std::uint64_t value, [[maybe_unused]] std::uint64_t expected) override {
        MemoryWrite64(vaddr, value);
        return true;
    }
    bool MemoryWriteExclusive128(u64 vaddr, Vector value, [[maybe_unused]] Vector expected) override {
        MemoryWrite128(vaddr, value);
        return true;
    }

    void InterpreterFallback(u64 pc, size_t num_instructions) override {
        ASSERT_MSG(false, "InterpreterFallback({:016x}, {})", pc, num_instructions);
    }

    void CallSVC(std::uint32_t swi) override {
        struct lfi_proc* p = lfi_sys_proc(jit->GetRegister(21));
        uint64_t result = p->lfi->opts.syshandler(p->ctxp,
                                                  jit->GetRegister(8),
                                                  jit->GetRegister(0),
                                                  jit->GetRegister(1),
                                                  jit->GetRegister(2),
                                                  jit->GetRegister(3),
                                                  jit->GetRegister(4),
                                                  jit->GetRegister(5));
        jit->SetRegister(0, result);
    }

    void ExceptionRaised(u64 pc, Dynarmic::A64::Exception) override {
        ASSERT_MSG(false, "ExceptionRaised({:016x})", pc);
    }

    void AddTicks(std::uint64_t ticks) override {
        if (ticks > ticks_left) {
            ticks_left = 0;
            return;
        }
        ticks_left -= ticks;
    }
    std::uint64_t GetTicksRemaining() override {
        return ticks_left;
    }
    std::uint64_t GetCNTPCT() override {
        return 0x10000000000 - ticks_left;
    }
};

int lfi_proc_entry_dynarmic(struct lfi_proc* proc) {
    char* backing_memory = nullptr;
    A64FastmemTestEnv env{backing_memory};
    Dynarmic::ExclusiveMonitor monitor{1};

    Dynarmic::A64::UserConfig config{&env};
    config.fastmem_pointer = reinterpret_cast<uintptr_t>(backing_memory);
    config.fastmem_address_space_bits = 64;
    config.recompile_on_fastmem_failure = false;
    config.silently_mirror_fastmem = true;
    config.fastmem_exclusive_access = true;
    config.recompile_on_exclusive_fastmem_failure = false;
    config.processor_id = 0;
    config.enable_cycle_counting = false;
    uint64_t tpidr_el0 = 0;
    config.tpidr_el0 = &tpidr_el0;
    config.global_monitor = &monitor;

    Dynarmic::A64::Jit jit{config};
    env.jit = &jit;

    std::array<std::uint64_t, 31> regs{proc->regs.x0,
                                       proc->regs.x1,
                                       proc->regs.x2,
                                       proc->regs.x3,
                                       proc->regs.x4,
                                       proc->regs.x5,
                                       proc->regs.x6,
                                       proc->regs.x7,
                                       proc->regs.x8,
                                       proc->regs.x8,
                                       proc->regs.x10,
                                       proc->regs.x11,
                                       proc->regs.x12,
                                       proc->regs.x13,
                                       proc->regs.x14,
                                       proc->regs.x15,
                                       proc->regs.x16,
                                       proc->regs.x17,
                                       proc->regs.x18,
                                       proc->regs.x19,
                                       proc->regs.x20,
                                       proc->regs.x21,
                                       proc->regs.x22,
                                       proc->regs.x23,
                                       proc->regs.x24,
                                       proc->regs.x25,
                                       proc->regs.x26,
                                       proc->regs.x27,
                                       proc->regs.x28,
                                       proc->regs.x29,
                                       proc->regs.x30};
    jit.SetRegisters(regs);
    jit.SetPC(proc->regs.x30);
    jit.SetSP(proc->regs.sp);
    jit.SetFpsr(0x3480000);
    jit.SetPstate(0x30000000);

    jit.Run();

    return 0;
}
