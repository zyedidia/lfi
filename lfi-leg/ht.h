#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

// ---
// redefine these values for custom types

typedef char* ht_key_t;
typedef int ht_val_t;

static uint64_t
ht_hash(ht_key_t str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

static inline bool
ht_eq(ht_key_t a, ht_key_t b)
{
    return strcmp(a, b) == 0;
}

// ---

struct ht_entry {
    ht_key_t key;
    ht_val_t val;
    bool filled;
};

struct ht {
    struct ht_entry* entries;
    size_t cap;
    size_t len;
};

int ht_alloc(struct ht* tbl, size_t cap);
void ht_free(struct ht* tbl);

ht_val_t ht_get(struct ht* tbl, ht_key_t key, bool* found);
int ht_put(struct ht* tbl, ht_key_t key, ht_val_t val);

extern struct ht labels;
