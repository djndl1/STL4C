#include "vector.h"

#include <stdio.h>

vector_type_register(int);

void f();

int main(int argc, char *argv[])
{
        vector_init(int, 20, NULL, b);

        vector_push_back(int, b, 5);
        vector_push_back(int, b, 20);
        vector_erase(int, b, 1);
        f();
        vector_delete(int, b);
        return 0;
}

