#include <stdio.h>
#include <stdlib.h>

struct GlobalStatContext {
    int indent;
    int num_stmt;
    int num_param;
    int num_arg;
    int type;
    bool is_const;

    bool func_call;
    Symbol sym;

    /* for search symbol */
    int search_base_type;
    int search_ret_type;
} global_stat_ctx;

struct LocalStatContext {
    int num_substat;
} local_stat_ctx;

#define TRACE0(tag) do {\
    for (int i = 0; i < global_stat_ctx.indent; i++) putchar('\t');\
    printf("[%-10s]\n", tag);\
} while(0)

#define TRACE(tag, fmt, ...) do {\
    for (int i = 0; i < global_stat_ctx.indent; i++) putchar('\t');\
    printf("[%-10s] " fmt "\n", tag, ##__VA_ARGS__);\
} while(0)

#define ERR(msg) do {\
    printf("[Error] %s\n", msg);\
    exit(EXIT_FAILURE);\
} while(0)
