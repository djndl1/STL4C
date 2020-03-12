#include "vector.h"

#include <stdio.h>

vector_type_register(int);

void f()
{
        vector_init(int, 5, NULL, a);

        vector_for_each(i, a)
                vector_at(a, i) = 1;

        vector_push_back(int, a, 20);

        vector_for_each(i, a)
                printf("%d ", vector_at(a, i));
        putchar('\n');

        vector_delete(int, a);
}
