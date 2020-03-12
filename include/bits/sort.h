#pragma once

#define basic_comparator_register(type)                                        \
  STL4C_WEAK_SYM bool stl4c_##type##_less(const type a, const type b) {         \
    return a < b;                                                              \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM bool stl4c_##type##_equal(const type a, const type b) {       \
    return a == b;                                                             \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM bool stl4c_##type##_greater(const type a, const type b) {     \
    return a > b;                                                              \
  }

#define sort_type_register(type, container)                                    \
  STL4C_WEAK_SYM ITER_TYPE(type, container)                                     \
  stl4c_##type##_##container##_certain_element(                                \
      ITER_TYPE(type, container) first, ITER_TYPE(type, container) last,       \
      bool (*pred)(const type, const type)) {                                  \
    if (first == last)                                                         \
      return first;                                                            \
    ITER_TYPE(type, container) certain = first;                                \
    for (; first != last; ITER_NEXT(first, container)) {                       \
      if (pred(ITER_DEREF(first, container), ITER_DEREF(certain, container)))  \
        certain = first;                                                       \
    }                                                                          \
    return certain;                                                            \
  }
