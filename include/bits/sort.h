#pragma once

#include "common.h"

#include "functional.h"

#define sort_type_register(type, container)                                    \
                                                                        \
  STL4C_WEAK_SYM ITER_TYPE(type, container)                                     \
      FUNC_NAME(type##_##container, certain_element)
(ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      bool (*pred)(const type, const type)) {                                  \
    if (first == last)                                                         \
      return first;                                                            \
    ITER_TYPE(type, container) certain = first;                                \
    for (; first != last; ITER_NEXT(first, container)) {                       \
      if (pred(ITER_DEREF(first, container), ITER_DEREF(certain, container)))  \
        certain = first;                                                       \
    }                                                                          \
    return certain;                                                            \
}                                                                       \
                                                                        \

