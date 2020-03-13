#pragma once

#include "config.h"

#ifdef __GNUC__
#define STL4C_WEAK_SYM __attribute__ ((weak))
#else
#define STL4C_WEAK_SYM
#endif

#define __type_name_generator(prefix, type, container) \
    prefix##_##type##_##container##_t

#define __func_name_generator(prefix, type, op)    \
    prefix##_##type##_##op

#ifdef STL4C_USING_NAMESPACE
#define TYPE_NAME(type, container) \
    __type_name_generator(stl4c, type, container)
#define FUNC_NAME(type, op) \
    __func_name_generator(stl4c, type, op)
#else
#define TYPE_NAME(type, container) \
    type##_##container##_t
#define FUNC_NAME(type, op) \
    type##_##op
#define STL_PREFIX
#endif // USING_NAMESPACE
