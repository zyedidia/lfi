#include "lfi.bdd.h"

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

struct node {
    uint8_t var;
    uint16_t lo;
    uint16_t hi;
};

static bool lookup(struct node* nodes, struct node* n, uint32_t val) {
    uint8_t bit = (val >> n->var) & 1;
    if (bit) {
        if (n->hi < 2) return n->hi;
        return lookup(nodes, &nodes[n->hi], val);
    }

    if (n->lo < 2) return n->lo;
    return lookup(nodes, &nodes[n->lo], val);
}

static struct node* bdd_nodes = (struct node*) generator_lfi_bdd;
static struct node* bdd_entry = (struct node*) (&generator_lfi_bdd)[sizeof(generator_lfi_bdd) / sizeof(struct node) - 1];

bool lfi_verify_bytes(char* b, size_t size, void* error) {
    (void) error;

    uint32_t* insns = (uint32_t*) b;

    for (size_t i = 0; i < size / sizeof(uint32_t); i++) {
        if (!lookup(bdd_nodes, bdd_entry, insns[i]))
            return false;
    }
    return true;
}
