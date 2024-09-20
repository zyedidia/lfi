#define SYSWRAP_0(name) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p); \
}

#define SYSWRAP_1(name, param0) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p, (param0)a0); \
}

#define SYSWRAP_2(name, param0, param1) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p, (param0)a0, (param1)a1); \
}

#define SYSWRAP_3(name, param0, param1, param2) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p, (param0)a0, (param1)a1, (param2)a2); \
}

#define SYSWRAP_4(name, param0, param1, param2, param3) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p, (param0)a0, (param1)a1, (param2)a2, (param3)a3); \
}

#define SYSWRAP_5(name, param0, param1, param2, param3, param4) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p, (param0)a0, (param1)a1, (param2)a2, (param3)a3, (param4)a4); \
}

#define SYSWRAP_6(name, param0, param1, param2, param3, param4, param5) \
static inline uintptr_t \
name##_(LFIXProc* p, uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) \
{ \
    return (uintptr_t) name(p, (param0)a0, (param1)a1, (param2)a2, (param3)a3, (param4)a4, (param5)a5); \
}
