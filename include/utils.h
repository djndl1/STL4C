#pragma once

#include <stdbool.h>

#define basic_swap(type, a, b)                         \
    do { type tmp = a; a = b; b = tmp; } while(0)

#define basic_max(type, a, b) ((a < b) ? b : a)
#define basic_min(type, a, b) ((a < b) ? a : b)

#define type_predicate_register(type)                                          \
  typedef bool (*type##_binary_predicate)(type, type);                         \
  typedef int(*type##_spaceship_comparator(type, type));                       \
                                                                               \
  STL4C_WEAK_SYM bool type##_default_binary_predicate(type a, type b) {        \
    return a == b;                                                             \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM int type##_default_spaceship_comparator(type a, type b) {      \
    if (a > b)                                                                 \
      return 1;                                                                \
    else if (a < b)                                                            \
      return -1;                                                               \
    else                                                                       \
      return 0;                                                                \
  }
