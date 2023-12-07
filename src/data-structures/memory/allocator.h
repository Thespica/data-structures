#ifndef DATA_STRUCT_ALLOCATOR_H
#define DATA_STRUCT_ALLOCATOR_H

#include <stddef.h>

/**
 * The allocator interface, which is used to allocate and deallocate memory.
 * <p>
 * The behavior of allocate, reallocate and deallocate
 * should similar to malloc, realloc and free in standard library.
 */
struct allocator {
    void* (*const allocate)(size_t size);
    void* (*const reallocate)(void* ptr, size_t size);
    void (*const deallocate)(void* ptr);
};

#endif  // DATA_STRUCT_ALLOCATOR_H
