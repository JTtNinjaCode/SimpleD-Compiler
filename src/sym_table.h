#ifndef SYM_TABLE_H
#define SYM_TABLE_H


/* expr type */
#define ET_INT      1
#define ET_BOOL     2
#define ET_FLOAT    3
#define ET_DOUBLE   4
#define ET_STRING   5
#define ET_VOID     6

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define SYMTAB_MAX      1024
#define SYMTAB_ERR_FULL 1
#define SYMTAB_ERR_DUP  2

typedef struct Symbol {
    bool valid;
    char name[128];             // hash key
    
    bool is_array;
    bool is_func;
    bool is_const;

    int param_num;
    int ary_dim_num;
    
    int base_type;
    int func_param_type[16];
    int ary_dim[16];
} Symbol;

typedef struct SymTab {
    Symbol syms[SYMTAB_MAX];
    struct SymTab *parent;
} SymTab;

typedef struct SymTabCtx {
    SymTab *root;
    SymTab *curr_st;
    int layer_count;

    /* call stack */
    SymTab *func_stk[1024];
    int curr_func;
    bool at_least_one_return;
} SymTabCtx;

extern SymTabCtx symtab_ctx;

void init_symtab_ctx();

void print_symtab_ctx();

// Global insert: inserts into the global symbol table `st`, return error code
int insert(Symbol *sym);
int insert_parent(Symbol *sym); /* used in function parameter */

// Global search: searches `st` and its parent tables
Symbol* search(const char *name);

// Add a new symbol table layer
void add_symtab_layer();
void push_func_to_stk(); /* call after add_symtab_layer */

// Delete the most recent symbol table layer
void delete_symtab_layer();
#endif // SYM_TABLE_H
