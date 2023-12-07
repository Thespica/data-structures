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