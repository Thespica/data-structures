#ifndef DATA_STRUCT_UTIL_H
#define DATA_STRUCT_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/base/nodes.h"
#include "data-structures/memory/allocator.h"
#include "data-structures/util/generic.h"

struct allocator allocator_instance = {
    .allocate = malloc, .reallocate = realloc, .deallocate = free};

void PrintIntNode(Node node) { printf("%d ", GetInt(node->value)); }

#endif  // DATA_STRUCT_UTIL_H