#pragma once

#include "common.h"

#define mutating_algorithm_register(type, container)                           \
  STL4C_WEAK_SYM void stl4c_##type##_##container##_##generate(                 \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      type (*gen)(void)) {                                                     \
    for (; first != last; ITER_NEXT(first, container))                         \
      ITER_DEREF(first, container) = gen();                                    \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM ITER_TYPE(type, container)                                    \
      stl4c_##type##_##container##_##generate_n(                               \
          ITER_TYPE(type, container) first, size_t n, type (*gen)(void)) {     \
    for (size_t i = 0; i < n; i++) {                                           \
      ITER_DEREF(first, container) = gen();                                    \
      ITER_NEXT(first, container);                                             \
    }                                                                          \
    return first;                                                              \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM ITER_TYPE(type, container)                                    \
      FUNC_NAME(type##_##container, fill)(ITER_TYPE(type, container) first,    \
                                          ITER_TYPE(type, container) last,     \
                                          const type value) {                  \
    for (; first != last; ITER_NEXT(container, first)) {                       \
      ITER_DEREF(container, first) = value;                                    \
    }                                                                          \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM ITER_TYPE(type, container)                                    \
      FUNC_NAME(type##_##container, fill_n)(ITER_TYPE(type, container) first,  \
                                            size_t n, const type value) {      \
    for (size_t i = 0; i < n; i++) {                                           \
      ITER_DEREF(first, container) = value;                                    \
      ITER_NEXT(first, container);                                             \
    }                                                                          \
    return first;                                                              \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM void FUNC_NAME(type##_##container, replace)(                  \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      const type old_value, const type new_value) {                            \
    for (; first != last; ITER_NEXT(container, first)) {                       \
      if (ITER_DEREF(container, first) == old_value)                           \
        ITER_DEREF(container, first) = new_value;                              \
    }                                                                          \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM void FUNC_NAME(type##_##container, replace_if)(               \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      bool (*pred)(type), const type new_value) {                              \
    for (; first != last; ITER_NEXT(container, first)) {                       \
      if (pred(ITER_DEREF(container, first)))                                  \
        ITER_DEREF(container, first) = new_value;                              \
    }                                                                          \
  }                                                                            \
                                                                               
