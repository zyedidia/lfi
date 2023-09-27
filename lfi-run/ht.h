#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// ---
// redefine these values for custom types

typedef uint64_t ht_key_t;
typedef uint64_t ht_val_t;

static inline uint64_t ht_hash(ht_key_t key) {
    key = ((key >> 16) ^ key) * 0x119de1f3;
    key = ((key >> 16) ^ key) * 0x119de1f3;
    key = (key >> 16) ^ key;
    return key;
}

static inline bool ht_eq(ht_key_t a, ht_key_t b) {
    return a == b;
}

// ---

typedef struct {
    ht_key_t key;
    ht_val_t val;
    bool filled;
} ht_entry_t;

typedef struct {
    ht_entry_t* entries;
    size_t cap;
    size_t len;
} ht_t;

int ht_alloc(ht_t* tbl, size_t cap);
void ht_free(ht_t* tbl);

ht_val_t ht_get(ht_t* tbl, ht_key_t key, bool* found);
int ht_put(ht_t* tbl, ht_key_t key, ht_val_t val);
int ht_remove(ht_t* tbl, ht_key_t key);
