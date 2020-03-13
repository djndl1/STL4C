#pragma once

#include "xmalloc.h"
#include "utils.h"
#include "common.h"


#define string_for_each vector_for_each
#define string_for_range vector_for_range
#define vector_for_each_in vector_for_each_in

#define string_type_register(type)              \
    typedef struct {           \
        type *data;                  \
                                                \
        size_t sz;                              \
        size_t space;                           \
    } TYPE_NAME(type, string);                         \
                                                \
    STL4C_WEAK_SYM TYPE_NAME(type, string) \
        FUNC_NAME(type##_string, new)(size_t sz) \
    {                                            \
        TYPE_NAME(type, string) var;             \
        var.data = xcalloc(sz+1, sizeof(type));  \
        var.sz = sz;                             \
        var.space = sz+1;                        \
                                                 \
        return var;                              \
    }


string_type_register(char);
