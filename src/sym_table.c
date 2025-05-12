#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sym_table.h"

SymTlb st = {};

unsigned hash(const char *str) {
    unsigned h = 5381;
    while (*str) h = ((h << 5) + h) + *str++;
    return h % TABLE_SIZE;
}

const char *lookup(const SymTlb st, const char *str) {
    unsigned h = hash(str);
    for (Symbol *s = st[h]; s; s = s->next) {
        if (strcmp(s->name, str) == 0) {
            return str;
        }
    }
    return NULL;
}

void insert(SymTlb st, const char *id) {
    unsigned h = hash(id);
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(id);
    sym->next = st[h];
    st[h] = sym;
}

void dump(SymTlb st) {
    printf("Symbol Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (Symbol *s = st[i]; s; s = s->next) {
            printf("%s\n", s->name);
        }
    }
}