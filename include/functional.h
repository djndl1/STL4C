#pragma once

#include "common.h"

#define basic_comparator_register(type)                                        \
  STL4C_WEAK_SYM bool FUNC_NAME(type, less)(const type a, const type b) {      \
    return a < b;                                                              \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM bool FUNC_NAME(type, equal_to)(const type a, const type b) {     \
    return a == b;                                                             \
  }                                                                            \
                                                                               \
  STL4C_WEAK_SYM bool FUNC_NAME(type, greater)(const type a, const type b) { return a > b; } \
  STL4C_WEAK_SYM bool FUNC_NAME(type, less_equal)(const type a, const type b) { return a <= b; } \
  STL4C_WEAK_SYM bool FUNC_NAME(type, greater_equal)(const type a, const type b) { return a >= b; } \
  STL4C_WEAK_SYM bool FUNC_NAME(type, not_equal_to)(const type a, const type b) { return a != b; }

#define arithmetic_operation_register(type)                                                 \
    STL4C_WEAK_SYM type FUNC_NAME(type, plus)(const type a, const type b) { return a + b; } \
    STL4C_WEAK_SYM type FUNC_NAME(type, minus)(const type a, const type b)                  \
    {                                                                                       \
        return a - b;                                                                       \
    }                                                                                       \
    STL4C_WEAK_SYM type FUNC_NAME(type, multiplies)(const type a, const type b)             \
    {                                                                                       \
        return a * b;                                                                       \
    }                                                                                       \
    STL4C_WEAK_SYM type FUNC_NAME(type, divides)(const type a, const type b)                \
    {                                                                                       \
        return a / b;                                                                       \
    }                                                                                       \
    \ 

    STL4C_WEAK_SYM type FUNC_NAME(type, modulus)(const type a, const type b) \
    {                                                                                       \
        return a % b;                                                                       \
    }                                                                                       \
    STL4C_WEAK_SYM type FUNC_NAME(type, negate)(const type a)                               \
    {                                                                                       \
        return -a;                                                                          \
    }

#define logical_operation_register(type)                                                            \
    STL4C_WEAK_SYM bool FUNC_NAME(type, logical_and)(const type a, const type b) { return a && b; } \
    STL4C_WEAK_SYM bool FUNC_NAME(type, logical_or)(const type a, const type b)                     \
    {                                                                                               \
        return a || b;                                                                              \
    }                                                                                               \
    STL4C_WEAK_SYM bool FUNC_NAME(type, logical_not)(const type a)                                  \
    {                                                                                               \
        return !a;                                                                                  \
    }

#define bitwise_operation_register(type)                                       \
  STL4C_WEAK_SYM                                                               \
  bool FUNC_NAME(type, bitwise_and)(const type a, const type b) {              \
    return a & b;                                                              \
  }                                                                            \
  STL4C_WEAK_SY bool FUNC_NAME(type, bitwise_or)(const type a, const type b) { \
    return a | b;                                                              \
  }                                                                            \
  STL4C_WEAK_SY bool FUNC_NAME(type, bitwise_xor)(const type a,                \
                                                  const type b) {              \
    return a ^ b;                                                              \
  }                                                                            \
  STL4C_WEAK_SY bool FUNC_NAME(type, bitwise_not)(const type a) { return ~a; }

#define stl4c_plus(type) \
    FUNC_NAME(type, plus)

#define stl4c_minus(type) FUNC_NAME(type, minus)

#define stl4c_multiplies(type) FUNC_NAME(type, multiplies)

#define stl4c_divides(type) FUNC_NAME(type, divides)

#define stl4c_modulus(type) FUNC_NAME(type, modulus)

#define stl4c_negate(type) FUNC_NAME(type, negate)
