#pragma once

#define SGR_ERR      "\033[1;91m"  // Bold red.
#define SGR_WARN     "\033[0;33m"  // Yellow.
#define SGR_WARN_DBG "\033[1;33m"  // Bold yellow.
#define SGR_INFO     "\033[0;96m"  // Cyan.
#define SGR_DEBUG    "\033[1;32m"  // Bold green.
#define SGR_RESET    "\033[0m"

#define VERBOSE(tux, fmt, ...)                                                          \
    do {                                                                                \
        if (tux->opts.verbose)                                                          \
            fprintf(stderr, "[libtux] " fmt "\n", ##__VA_ARGS__);                       \
    } while (0)

#define INFO(fmt, ...)                                                                  \
    do {                                                                                \
        fprintf(stderr, SGR_INFO "[libtux] " fmt SGR_RESET "\n", ##__VA_ARGS__);        \
    } while (0)

#define WARN(fmt, ...)                                                                  \
    do {                                                                                \
        fprintf(stderr, SGR_WARN "[libtux] WARN: " fmt SGR_RESET "\n", ##__VA_ARGS__);  \
    } while (0)

#define DBG(fmt, ...)                                                                   \
    do {                                                                                \
        fprintf(stderr, SGR_DEBUG "[libtux]: " fmt SGR_RESET "\n", ##__VA_ARGS__);      \
    } while (0)
