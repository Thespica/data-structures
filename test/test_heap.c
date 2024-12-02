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

#include "util.h"

#include "data-structures/tree/heap.h"

int main(void) {
    Heap heap = NewHeap(NewInt(1), 10, IntCmp);
    for (int i = 2; i < 10; i++) {
        InsertHeap(heap, NewInt(i));
    }
    while (heap->size) {
        printf("%d ", DeleteAndGetInt(PopHeap(heap)));
    }
    DeleteHeap(heap);
    return 0;
}