#pragma once

#include "common.h"
#include "iterator.h"

#include <stdbool.h>

#define double_iter_func(type, cont1, cont2, func_name)\
        FUNC_NAME(type##_##cont1##_##cont2##, func_name)

#define __generate_multi_iter_search(type, cont1, cont2)                                                    \
    ITER_TYPE(type, cont1)                                                                                  \
    double_iter_func(type, cont1, cont2, search)(ITER_TYPE(type, cont1) first, ITER_TYPE(type, cont1) last, \
        ITER_TYPE(type, cont2) s_first, ITER_TYPE(type, cont2) s_last,                                      \
        bool (*pred)(const type, const type))                                                               \
    {                                                                                                       \
        if (s_first == s_last)                                                                              \
            return first;                                                                                   \
                                                                                                            \
        while (true) {                                                                                      \
            while (true) {                                                                                  \
                if (first == last)                                                                          \
                    return last;                                                                            \
                if (pred(ITER_DEREF(cont1, first), ITER_DEREF(cont2, s_first)))                             \
                    break;                                                                                  \
                ITER_NEXT(cont1, first);                                                                    \
            }                                                                                               \
                                                                                                            \
            ITER_TYPE(type, cont1) elm_it1 = first;                     \
            ITER_TYPE(type, cont2) ele_it2 = s_first;                   \
                                                                                                            \
            while (true) {                                                                                  \
                ITER_NEXT(cont2, elm_it2);                                                                  \
                if (elm_it2 == s_last)                                                                      \
                    return first;                                                                           \
                                                                                                            \
                ITER_NEXT(cont1, elm_it1);                                                                  \
                if (elm_it1 == last)                                                                        \
                    return last;                                                                            \
                                                                                                            \
                if (!pred(ITER_DEREF(cont1, elm_it1), ITER_DEREF(cont2, elm_it2))) {                        \
                    ITER_NEXT(cont1, first);                                                                \
                    break;                                                                                  \
                }                                                                                           \
            }                                                                                               \
        }                                                                                                   \
    }

#define use_multi_iter_func(type, cont1, cont2, func)   \
        __generate_multi_iter_##func(type, cont1, cont2)

#define stl4c_search_pred(type, cont1, cont2, first, last, s_first, s_last, pred)\
    double_iter_func(type, cont1, cont2, search)(first, last, s_first, s_last, pred)

#define stl4c_search(type, cont1, cont2, first, last, s_first, s_last)\
        double_iter_func(type, cont1, cont2, search)(first, last, s_first, s_last, stl4c_equal_to(type))
