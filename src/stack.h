// fixed_stack.h
#ifndef FIXED_STACK_H
#define FIXED_STACK_H

#include <assert.h>
#include <stddef.h>

#define STACK_MAX 2048

#define DEFINE_FIXED_STACK(TYPE, NAME)                             \
    typedef struct {                                               \
        TYPE data[STACK_MAX];                                      \
        size_t size;                                               \
    } NAME##Stack;                                                 \
                                                                   \
    static inline void NAME##Stack_init(NAME##Stack* s) {          \
        s->size = 0;                                               \
    }                                                              \
                                                                   \
    static inline void NAME##Stack_push(NAME##Stack* s, TYPE v) {  \
        assert(s->size < STACK_MAX && "stack overflow");           \
        s->data[s->size++] = v;                                    \
    }                                                              \
                                                                   \
    static inline TYPE NAME##Stack_pop(NAME##Stack* s) {           \
        assert(s->size > 0 && "stack underflow");                  \
        return s->data[--s->size];                                 \
    }                                                              \
                                                                   \
    static inline TYPE NAME##Stack_top(const NAME##Stack* s) {     \
        assert(s->size > 0 && "stack empty");                      \
        return s->data[s->size - 1];                               \
    }                                                              \
                                                                   \
    static inline int NAME##Stack_empty(const NAME##Stack* s) {    \
        return s->size == 0;                                       \
    }                                                              \
                                                                   \
    static inline size_t NAME##Stack_size(const NAME##Stack* s) {  \
        return s->size;                                            \
    }

#endif // FIXED_STACK_H
