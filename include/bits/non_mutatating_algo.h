#pragma once

#define non_mutating_algorithm_register(type, container)                       \
  STL4C_WEAK_SYM void stl4c_##type##_##container##_for_each(                    \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      void (*func)(const type)) {                                              \
    for (; first != last; ITER_NEXT(first, container)) {                       \
      func(ITER_DEREF(first, container));                                      \
    }                                                                          \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM size_t stl4c_##type##_##container##_count_if(                 \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      bool (*pred)(const type)) {                                              \
    size_t cnt = 0;                                                            \
    for (; first != last; ITER_NEXT(first, container)) {                       \
      if (pred(ITER_DEREF(first, container)))                                  \
        cnt++;                                                                 \
    }                                                                          \
    return cnt;                                                                \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM size_t stl4c_##type##_##container##_count(                    \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      const type value) {                                                      \
    size_t cnt = 0;                                                            \
    for (; first != last; ITER_NEXT(first, container)) {                       \
      if (ITER_DEREF(first, container) == value)                               \
        cnt++;                                                                 \
    }                                                                          \
    return cnt;                                                                \
  }
