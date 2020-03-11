#pragma once

#define mutating_algorithm_register(type, container)                          \
        void stl4c_##type##_##container##_##generate(ITER_TYPE(type, container) first, ITER_TYPE(type, container) last, type (*gen)(void)) { \
        for (; first != last; ITER_NEXT(first, container))              \
                ITER_DEREF(first, container) = gen();                             \
    }                                                                   \
                                                                        \
        ITER_TYPE(type, container) stl4c_##type##_##container##_##generate_n(ITER_TYPE(type, container) first, size_t n, type(*gen)(void)) \
        {                                                               \
                for (size_t i = 0; i < n; i++) {                        \
                        ITER_DEREF(first, container) = gen();                     \
                        ITER_NEXT(first, container);                              \
                }                                                       \
                return first;                                           \
        }                                            
