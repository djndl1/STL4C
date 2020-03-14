#pragma once

#include "common.h"
#include "iterator.h"
#include "functional.h"

#define numeric_type_register(type, container)                             \
    arithmetic_operation_register(type);                            \
    type FUNC_NAME(type, accumulate)(ITER_TYPE(type, container) first,     \
        ITER_TYPE(type, container) last, type init, type(*op)(type, type)) \
    {                                                                      \
        for (; first != last; ITER_NEXT(container, first)) {               \
            init = op(init, ITER_DEREF(container, first));                 \
        }                                                                  \
        return init;                                                       \
    }




#define stl4c_accumulate(type, first, last) \
        FUNC_NAME(type, accumulate)(first, last, stl4c_plus)

#define stl4c_accumulate_pred(type, first, bin_op)        \
        FUNC_NAME(type, accumulate)(first, last, bin_op)
