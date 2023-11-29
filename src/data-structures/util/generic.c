#include "data-structures/util/generic.h"

#include <stdlib.h>
#include <stdio.h>

#include "data-structures/memory/allocator.h"
#include "data-structures/util/error_code.h"

extern struct allocator allocator_instance;

int *NewInt(int value) {
    int *ptr = (int *)allocator_instance.allocate(sizeof(int));
    *ptr = value;
    return ptr;
}

void SetInt(void *ptr, int value) { *((int *)ptr) = value; }

int GetInt(void *ptr) { return *((int *)ptr); }

int IntPrefInc(void *ptr) { return ++(*((int *)ptr)); }

int IntPostInc(void *ptr) { return (*((int *)ptr))++; }

int IntPrefDec(void *ptr) { return --(*((int *)ptr)); }

int IntPostDec(void *ptr) { return (*((int *)ptr))--; }

int DeleteAndGetInt(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Error: try to delete null as int\n");
        exit(FREE_NULL_POINTER_FAIL);
    }
    const int value = *(int *)ptr;
    allocator_instance.deallocate(ptr);
    return value;
}