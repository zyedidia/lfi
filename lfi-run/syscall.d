module syscall;

import core.lib;

import sysno;
import proc;

extern (C) void syscall_handler(Proc* p) {
    ulong sysno = p.regs.x8;

    switch (sysno) {
    case SYS_EXIT_GROUP, SYS_EXIT:
        printf("exit\n");
        exit(1);
        break;
    default:
        fprintf(stderr, "unknown syscall: %ld\n", sysno);
        exit(1);
    }
}
