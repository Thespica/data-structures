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
