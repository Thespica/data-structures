#ifndef DATA_STRUCT_ARRAY_H
#define DATA_STRUCT_ARRAY_H

#include <stddef.h>

#include "data-structures/memory/allocator.h"

extern struct allocator allocator;

/**
 * Use void pointer to hold the actual element value
 */
typedef void* ArrayValue;

struct array {
    size_t size;
    // Flexible array member, which is a C99 feature
    ArrayValue array[0];
};

/**
 * The array as a whole, which has a size and a flexible array(whose element type is void*) member
 */
typedef struct array* Array;

/**
 * Construct an array. Whole element in array will be initialized to NULL.
 *
 * @param size Size of array
 * @return Pointer of the array
 */
Array NewArray(size_t size);

/**
 * Get size of the array
 * @param array Pointer of the array
 * @return Size of the array
 */
size_t GetSizeArray(Array array);

/**
 * Resize the array.
 * If new_size is smaller than original size, the elements in the tail will be lost.
 * If new_size is equal to original size, the array will not be changed.
 * If new_size is larger than original size, the new elements will be initialized to NULL.
 *
 * @param array Pointer of the array
 * @param new_array_size New size of the array
 * @return Pointer of the new array
 */
Array ResizeArray(Array array, size_t new_array_size);

/**
 * Get the array value at position. The position should starts from 0
 *
 * @param array Pointer of the array
 * @param position Position of the array, begin with 0
 * @return A pointer to the actual value in heap
 */
ArrayValue GetValueAtArray(Array array, size_t position);

/**
 * Replace the array value at position. The position starts from 0.
 * The original value must be hold or free.
 *
 * @param array Pointer of the array
 * @param position Position of the array, begin with 0
 * @param value Pointer to the actual value in heap
 * @return Pointer of the original value, which must be hold or free
 */
ArrayValue ReplaceValueAtArray(Array array, size_t position, ArrayValue value);

/**
 * Delete the array in heap
 *
 * @param array Pointer of the array
 */
void DeleteArray(Array array);

#endif  // DATA_STRUCT_ARRAY_H
