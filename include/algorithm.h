#pragma once

#include <stddef.h>

#include "iterator.h"

#include "bits/mutating_algo.h"

#include "bits/non_mutatating_algo.h"

#include "bits/sort.h"


#define stl4c_generic_algorithm(type, container, algo)   \
        stl4c_##type##_##container##_##algo

#define stl4c_generate(type, container, first, last, generator)              \
        stl4c_generic_algorithm(type, container, generate)(first, last, generator)





#define stl4c_for_each(type, container, first, last, function) \
        stl4c_generic_algorithm(type, container, for_each)(first, last, function)

#define stl4c_count_if(type, container, first, last, predicate) \
        stl4c_generic_algorithm(type, container, count_if)(first, last, predicate)

#define stl4c_count(type, container, first, last, value)         \
        stl4c_generic_algorithm(type, container, count)(first, last, value)

#define stl4c_less(type)                        \
        stl4c_##type##_less

#define stl4c_greater(type)                        \
        stl4c_##type##_greater

#define stl4c_equal(type)                     \
        stl4c_##type##_equal

#define stl4c_certain_element(type, container, first, last, comparator)\
        stl4c_generic_algorithm(type, container, certain_element)(first, last, comparator)

