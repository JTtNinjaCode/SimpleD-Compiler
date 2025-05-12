#include "sym_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymTabCtx symtab_ctx;

static unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % SYMTAB_MAX;
}

void init_symtab_ctx() {
    symtab_ctx.root = (SymTab *)calloc(1, sizeof(SymTab));
    symtab_ctx.curr_st = symtab_ctx.root;
    symtab_ctx.layer_count = 1;
}

// Insert into a specific table using open addressing
static int insert_to_table(SymTab *st, Symbol *sym) {
    unsigned long h = hash(sym->name);
    for (int i = 0; i < SYMTAB_MAX; ++i) {
        int idx = (h + i) % SYMTAB_MAX;
        Symbol *slot = &st->syms[idx];

        if (!slot->valid) {
            *slot = *sym;
            slot->valid = true;
            return 0;
        }

        if (strcmp(slot->name, sym->name) == 0) {
            return SYMTAB_ERR_DUP;
        }
    }
    return SYMTAB_ERR_FULL;
}

int insert(Symbol *sym) {
    if (!symtab_ctx.curr_st) {
        fprintf(stderr, "Error: Symbol table context not initialized.\n");
        return -1;
    }
    return insert_to_table(symtab_ctx.curr_st, sym);
}

int insert_parent(Symbol *sym) {
    if (!symtab_ctx.curr_st->parent) {
        fprintf(stderr, "Error: Symbol table context not initialized.\n");
        return -1;
    }
    return insert_to_table(symtab_ctx.curr_st->parent, sym);
}

Symbol* search(const char *name) {
    SymTab *st = symtab_ctx.curr_st;
    while (st) {
        unsigned long h = hash(name);
        for (int i = 0; i < SYMTAB_MAX; ++i) {
            int idx = (h + i) % SYMTAB_MAX;
            Symbol *slot = &st->syms[idx];

            if (!slot->valid)
                break; // early exit: empty slot found

            if (strcmp(slot->name, name) == 0) {
                return slot;
            }
        }
        st = st->parent;
    }
    return NULL;
}

void add_symtab_layer() {
    SymTab *new_layer = (SymTab *)calloc(1, sizeof(SymTab));
    new_layer->parent = symtab_ctx.curr_st;
    symtab_ctx.curr_st = new_layer;
    symtab_ctx.layer_count++;
}

void delete_symtab_layer() {
    if (symtab_ctx.curr_st && symtab_ctx.curr_st != symtab_ctx.root) {
        SymTab *to_free = symtab_ctx.curr_st;
        symtab_ctx.curr_st = to_free->parent;
        free(to_free);
        symtab_ctx.layer_count--;
    }
}

static const char *type_to_str(int t) {
    switch (t) {
        case INT:       return "int";
        case FLOAT:     return "float";
        case DOUBLE:    return "double";
        case STRING:    return "string";
        case VOID:      return "void";
        default:        return "unknown";
    }
}

void print_symtab_single(const SymTab *st, int depth) {
    printf("Symbol Table [Layer %d]================================================================\n", depth);
    printf("%-20s %-10s %-8s %-8s %-8s %-10s %-10s\n", "Name", "Type", "Array", "Function", "Const", "ParamNum", "AryDimNum");

    for (int i = 0; i < SYMTAB_MAX; ++i) {
        const Symbol *sym = &st->syms[i];
        if (sym->valid) {
            printf("%-20s %-10s %-8s %-8s %-8s %-10d %-10d\n",
                   sym->name,
                   type_to_str(sym->base_type),
                   sym->is_array ? "yes" : "no",
                   sym->is_func  ? "yes" : "no",
                   sym->is_const ? "yes" : "no",
                   sym->param_num,
                   sym->ary_dim_num
                );
        }
    }
    printf("======================================================================================\n");
}

void print_symtab_ctx() {
    SymTab *st = symtab_ctx.curr_st;
    int depth = symtab_ctx.layer_count;

    while (st) {
        print_symtab_single(st, depth--);
        st = st->parent;
    }
}
