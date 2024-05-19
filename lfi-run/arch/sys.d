module arch.sys;

version (arm64) {
    public import arch.arm64.sys;
} else version (amd64) {
    public import arch.amd64.sys;
}
