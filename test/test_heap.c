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