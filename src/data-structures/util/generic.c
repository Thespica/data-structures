#include "data-structures/util/generic.h"

#include "data-structures/memory/allocator.h"

extern struct allocator allocator_instance;

int *NewInt(int value) {
    int *ptr = (int*)allocator_instance.allocate(sizeof(int));
    *ptr = value;
    return ptr;
}

void SetInt(void *ptr, int value) {
    *((int*)ptr) = value;
}

int GetInt(void *ptr) {
    return *((int*)ptr);
}

int IntPrefInc(void *ptr) {
    return ++(*((int*)ptr));
}

int IntPostInc(void *ptr) {
    return (*((int*)ptr))++;
}

int IntPrefDec(void *ptr) {
    return --(*((int*)ptr));
}

int IntPostDec(void *ptr) {
    return (*((int*)ptr))--;
}