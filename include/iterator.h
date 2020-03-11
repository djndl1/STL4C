#pragma once

#include "vector.h"
#include "list.h"

#define ITER_DEREF(iter, container) container##_iter_deref(iter)

#define ITER_NEXT(iter, container) container##_iter_next(iter)

#define ITER_TYPE(type, container) container##_iter_type(type)

#define vector_iter_next(iter) (iter++)

#define vector_iter_deref(iter) (*iter)

#define vector_iter_type(type) type*

#define list_iter_next(iter) (iter = iter->next)

#define list_iter_deref(iter) (iter->data)

#define list_iter_type(type) type##_list_node_t*
