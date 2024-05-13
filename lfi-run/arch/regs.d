module arch.regs;

version (arm64) {
    public import arch.arm64.regs;
} else version (amd64) {
    public import arch.amd64.regs;
}
