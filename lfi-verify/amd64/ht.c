#include <errno.h>
#include <stdlib.h>

#include "ht.h"

static size_t pow2ceil(size_t num) {
    size_t power = 1;
    while (power < num) {
        power *= 2;
    }
    return power;
}

int ht_alloc(ht_t* tbl, size_t caphint) {
    tbl->len = 0;
    tbl->cap = pow2ceil(caphint);

    tbl->entries = (ht_entry_t*) calloc(tbl->cap, sizeof(ht_entry_t));
    if (tbl->entries == NULL) {
        return -ENOMEM;
    }
    return 0;
}

void ht_free(ht_t* tbl) {
    free(tbl->entries);
}

ht_val_t ht_get(ht_t* tbl, ht_key_t key, bool* found) {
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

static int resize(ht_t* tbl, size_t newcap) {
    ht_entry_t* entries = (ht_entry_t*) calloc(newcap, sizeof(ht_entry_t));
    if (entries == NULL) {
        return -ENOMEM;
    }

    ht_t newht = (ht_t){
        .cap = newcap,
        .len = tbl->len,
        .entries = entries,
    };

    for (size_t i = 0; i < tbl->cap; i++) {
        ht_entry_t ent = tbl->entries[i];
        if (ent.filled) {
            ht_put(&newht, ent.key, ent.val);
        }
    }

    free(tbl->entries);

    tbl->cap = newht.cap;
    tbl->entries = newht.entries;

    return 0;
}

int ht_put(ht_t* tbl, ht_key_t key, ht_val_t val) {
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

static void remove(ht_t* tbl, size_t idx) {
    tbl->entries[idx].filled = false;
    tbl->len--;
}

int ht_remove(ht_t* tbl, ht_key_t key) {
    uint64_t hash = ht_hash(key);
    size_t idx = (size_t) (hash & (uint64_t) (tbl->cap - 1));

    while (tbl->entries[idx].filled && !ht_eq(tbl->entries[idx].key, key)) {
        idx = (idx + 1) & (tbl->cap - 1);
    }

    if (!tbl->entries[idx].filled) {
        return 0;
    }

    remove(tbl, idx);

    idx = (idx + 1) & (tbl->cap - 1);

    while (tbl->entries[idx].filled) {
        ht_key_t krehash = tbl->entries[idx].key;
        ht_val_t vrehash = tbl->entries[idx].val;
        remove(tbl, idx);
        ht_put(tbl, krehash, vrehash);
        idx = (idx + 1) & (tbl->cap - 1);
    }

    // halves the array if it is 12.5% full or less
    if (tbl->len > 0 && tbl->len <= tbl->cap / 8) {
        return resize(tbl, tbl->cap / 2);
    }
    return 0;
}
