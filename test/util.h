#ifndef DATA_STRUCT_UTIL_H
#define DATA_STRUCT_UTIL_H

#include <stdlib.h>

#include "data-structures/memory/allocator.h"

struct allocator allocator_instance = {
        .allocate = malloc,
        .reallocate = realloc,
        .deallocate = free
};

#endif //DATA_STRUCT_UTIL_H
