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
