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

#include "data-structures/util/generic.h"

#include "data-structures/memory/allocator.h"

extern struct allocator allocator_instance;

int* NewInt(int value) {
    int* ptr = (int*)allocator_instance.allocate(sizeof(int));
    *ptr = value;
    return ptr;
}

void SetInt(Int ptr, int value) { *(int*)ptr = value; }

int GetInt(Int ptr) { return *(int*)ptr; }

int IntPrefInc(Int ptr) { return ++(*(int*)ptr); }

int IntPostInc(Int ptr) { return (*(int*)ptr)++; }

int IntPrefDec(Int ptr) { return --(*(int*)ptr); }

int IntPostDec(Int ptr) { return (*(int*)ptr)--; }

int DeleteAndGetInt(Int ptr) {
    const int value = *(int*)ptr;
    allocator_instance.deallocate(ptr);
    return value;
}

bool IntCmp(Int ptr1, Int ptr2) { return GetInt(ptr1) < GetInt(ptr2); }

bool IntEq(Int ptr1, Int ptr2) { return GetInt(ptr1) == GetInt(ptr2); }