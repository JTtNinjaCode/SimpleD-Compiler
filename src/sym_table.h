#define  TABLE_SIZE 64
typedef struct Symbol {
    const char *name;
    const char *type;
    int scope;
    struct Symbol *next;
} Symbol;

typedef Symbol* SymTlb[TABLE_SIZE] ;
extern SymTlb st;

unsigned hash(const char *str);
const char *lookup(const SymTlb st, const char *str);
void insert(SymTlb st, const char *id);
void dump(SymTlb st);