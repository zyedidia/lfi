#pragma once

struct op {
    char* text;

    bool insn;
    bool code;
    char* label;

    bool shortbr;
    char* replace;
    char* target;

    struct op* next;
};

struct op;

struct op* mktbz(char* tbz, char* reg, char* imm, char* label);

struct op* mklabel(char* name);

struct op* mkinsn(char* fmt, ...);

struct op* mkdirective(char* text);

struct op* mkcodedirective(char* text);

extern struct op* ops;
