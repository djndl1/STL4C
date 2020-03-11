#include "algorithm.h"
#include "vector.h"
#include "list.h"
#include "utils.h"
#include <stdio.h>

vector_type_register(int);
list_type_register(int);
type_predicate_register(int);
mutating_algorithm_register(int, vector);
mutating_algorithm_register(int, list);
non_mutating_algorithm_register(int, list);
non_mutating_algorithm_register(int, vector);

sort_type_register(int ,vector);
basic_comparator_register(int);

int intGen(void) {
  static int i = 1;
  return i++;
}

void printer(const int a) {
        printf("It's %d\n", a);
}

bool isEven(const int n) {
        return !(n & 1u);
        
}

int main(int argc, char *argv[])
{
        vector_init(int, 20, NULL, intarr);
        list_init(int, NULL, intlist);
        for (size_t i = 0; i < 20; i++)
                list_push_back(int, intlist, 0);

        stl4c_generate(int, vector, vector_begin(intarr),
                       vector_end(intarr), intGen);
        
        vector_for_each(i, intarr) {
                printf("%d ", vector_at(intarr, i));
        }
        putchar('\n');

        stl4c_generate(int, list, list_begin(intlist), list_end(intlist), intGen);
        list_for_each_next(int, it, intlist) {
                printf("%d ", ITER_DEREF(it, list));
        }
        putchar('\n');

        stl4c_for_each(int, list, list_begin(intlist), list_end(intlist), printer);
        stl4c_for_each(int, vector, vector_begin(intarr), vector_end(intarr),
                       printer);

        size_t cnt1 = stl4c_count_if(int, vector, vector_begin(intarr),
                                    vector_end(intarr), isEven);
        size_t cnt2 = stl4c_count(int, vector, vector_begin(intarr),
                                     vector_end(intarr), 11);
        printf("there is %zu even numbers in the vector\n,  %zu elevens\n", cnt1, cnt2);

        size_t cnt3 = stl4c_count_if(int, list, list_begin(intlist),
                                     list_end(intlist), isEven);
        size_t cnt4 = stl4c_count(int, list, list_begin(intlist),
                                  list_end(intlist), 11);
        printf("there is %zu even numbers in the list\n,  %zu elevens\n",
               cnt3, cnt4);

        ITER_TYPE(int, vector) smlst = stl4c_certain_element(int, vector, vector_begin(intarr), vector_end(intarr), stl4c_less(int));
        ITER_TYPE(int, vector)
        greatest = stl4c_certain_element(int, vector, vector_begin(intarr),
                                      vector_end(intarr), stl4c_greater(int));
        printf("The smallest %d and the greatest %d in the vector\n", ITER_DEREF(smlst, vector), ITER_DEREF(greatest, vector));
        return 0;
}


