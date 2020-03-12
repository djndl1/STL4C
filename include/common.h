#pragma once

#ifdef __GNUC__
#define STL4C_WEAK_SYM __attribute__ ((weak))
#else
#define STL4C_WEAK_SYM
#endif
