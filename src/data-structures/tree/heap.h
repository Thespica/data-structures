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

#ifndef DATA_STRUCTURES_HEAP_H
#define DATA_STRUCTURES_HEAP_H

#include <stdbool.h>

#include "data-structures/base/array.h"

struct heap {
    Array array;
    int size;
    bool (*compare)(Value low_priority, Value high_priority);
};

typedef struct heap* Heap;

Heap NewHeap(Value value, int capacity, bool (*compare)(Value high_priority, Value low_priority));

void InsertHeap(Heap heap, Value value);

Value TopHeap(Heap heap);

Value PopHeap(Heap heap);

void DeleteHeap(Heap heap);

#endif  // DATA_STRUCTURES_HEAP_H
