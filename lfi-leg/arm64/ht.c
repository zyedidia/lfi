#include <errno.h>
#include <stdlib.h>

#include "ht.h"

static size_t
pow2ceil(size_t num)
{
    size_t power = 1;
    while (power < num) {
        power *= 2;
    }
    return power;
}

int
ht_alloc(struct ht* tbl, size_t caphint)
{
    tbl->len = 0;
    tbl->cap = pow2ceil(caphint);

    tbl->entries = (struct ht_entry*) calloc(tbl->cap, sizeof(struct ht_entry));
    if (tbl->entries == NULL) {
        return -ENOMEM;
    }
    return 0;
}

void
ht_free(struct ht* tbl)
{
    free(tbl->entries);
}

ht_val_t
ht_get(struct ht* tbl, ht_key_t key, bool* found)
{
    uint64_t hash = ht_hash(key);
    size_t idx = (size_t) (hash & (uint64_t) (tbl->cap - 1));

    while (tbl->entries[idx].filled) {
        if (ht_eq(tbl->entries[idx].key, key)) {
            if (found)
                *found = true;
            return tbl->entries[idx].val;
        }
        idx++;
        if (idx >= tbl->cap) {
            idx = 0;
        }
    }
    if (found)
        *found = false;

    ht_val_t val;
    memset(&val, 0, sizeof(ht_val_t));
    return val;
}

static int
resize(struct ht* tbl, size_t newcap)
{
    struct ht_entry* entries = (struct ht_entry*) calloc(newcap, sizeof(struct ht_entry));
    if (entries == NULL) {
        return -ENOMEM;
    }

    struct ht newht = (struct ht){
        .cap = newcap,
        .len = tbl->len,
        .entries = entries,
    };

    for (size_t i = 0; i < tbl->cap; i++) {
        struct ht_entry ent = tbl->entries[i];
        if (ent.filled) {
            ht_put(&newht, ent.key, ent.val);
        }
    }

    free(tbl->entries);

    tbl->cap = newht.cap;
    tbl->entries = newht.entries;

    return 0;
}

int
ht_put(struct ht* tbl, ht_key_t key, ht_val_t val)
{
    if (tbl->len >= tbl->cap / 2) {
        int err = resize(tbl, tbl->cap * 2);
        if (err < 0) {
            return err;
        }
    }

    uint64_t hash = ht_hash(key);
    size_t idx = (size_t) (hash & (uint64_t) (tbl->cap - 1));

    while (tbl->entries[idx].filled) {
        if (ht_eq(tbl->entries[idx].key, key)) {
            tbl->entries[idx].val = val;
            return 0;
        }
        idx++;
        if (idx >= tbl->cap) {
            idx = 0;
        }
    }

    tbl->entries[idx].key = key;
    tbl->entries[idx].val = val;
    tbl->entries[idx].filled = true;
    tbl->len++;

    return 0;
}
