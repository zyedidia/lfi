# LFI Arm64 Verifier

Welcome to the Arm64 LFI verifier. The verifier supports several different
configurations.

## Base LFI Verification

The default configuration of the verifier allows only the instructions listed
in `base.instrs`. The verifier ensures that loads, stores, and indirect
branches are confined to the sandbox. The core verification code is implemented
in `verify.c`.

## Position-Oblivious Code

Position-oblivious code enforces that all pointers in the sandbox are relative
to the base, such that the sandboxed code cannot determine what its base
address is. This makes it possible to implement fork with LFI sandboxes, and
removes any observable non-determinism related to the sandbox's base address.
The code for verifying this property is stored in `poc.c`.

## Determinism Enforcement

This configuration, used by DeCl, further restricts instructions to a set of
only deterministic instructions, listed in `decl.instrs`. This configuration
also assumes the runtime call entrypoint is stored at `x25` rather than at the
base of the sandbox.

## Metering Enforcement

This configuration, used by DeCl, enforces that programs track their
instruction execution count and self-terminate if it reaches a maximum. This is
used to implement deterministic preemption. The code for this is stored in
`meter.c`.
