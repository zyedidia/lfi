#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

struct BDDNode {
    uint16_t v;
    uint16_t lo;
    uint16_t hi;
    uint8_t terminal_hi;
    uint8_t terminal_lo;
};

static uint8_t lookup(struct BDDNode *nodes, struct BDDNode *n, uint8_t *input) {
    uint8_t bit = (input[n->v/8] >> (7 - (n->v % 8))) & 1;
    if (bit) {
        if (n->terminal_hi)
            return n->hi;
        return lookup(nodes, &nodes[n->hi], input);
    }

    if (n->terminal_lo)
        return n->lo;
    return lookup(nodes, &nodes[n->lo], input);
}

extern uint8_t lfi_bdd_data[];

static uint16_t *entry = (uint16_t *) &lfi_bdd_data[0];
static struct BDDNode *bdd_nodes = (struct BDDNode *) &lfi_bdd_data[2];

uint8_t lfi_x86_bdd(uint8_t *input) {
    uint8_t size = lookup(bdd_nodes, &bdd_nodes[*entry], input);
    return size;
}
