/*
 * Copyright 2024 Thespica
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DATA_STRUCT_ARRAY_H
#define DATA_STRUCT_ARRAY_H

#include <stddef.h>

#include "data-structures/memory/allocator.h"

extern struct allocator allocator;

/**
 * Use void pointer to hold the actual element value
 */
typedef void* Value;

struct array {
    size_t capacity;
    // Flexible array member, which is a C99 feature
    Value array[0];
};

/**
 * The array as a whole, which has a capacity and a flexible array(whose element type is void*) member
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
 * Get capacity of the array
 * @param array Pointer of the array
 * @return Size of the array
 */
size_t GetSizeArray(Array array);

/**
 * Resize the array.
 * If new_size is smaller than original capacity, the elements in the tail will be lost.
 * If new_size is equal to original capacity, the array will not be changed.
 * If new_size is larger than original capacity, the new elements will be initialized to NULL.
 *
 * @param array Pointer of the array
 * @param new_array_size New capacity of the array
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
Value GetValueAtArray(Array array, size_t position);

/**
 * Replace the array value at position. The position starts from 0.
 * The original value must be hold or free.
 *
 * @param array Pointer of the array
 * @param position Position of the array, begin with 0
 * @param value Pointer to the actual value in heap
 * @return Pointer of the original value, which must be hold or free
 */
Value ReplaceValueAtArray(Array array, size_t position, Value value);

/**
 * Delete the array in heap
 *
 * @param array Pointer of the array
 */
void DeleteArray(Array array);

#endif  // DATA_STRUCT_ARRAY_H
