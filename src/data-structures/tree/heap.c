#include "data-structures/tree/heap.h"

#include "data-structures/memory/allocator.h"
#include "data-structures/util/error_code.h"

extern struct allocator allocator_instance;

static inline int ParentIdx(int idx) { return (idx - 1) / 2; }

static void SwapValue(Value* value1, Value* value2) {
    Value temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

static void ValuePushUp(Heap heap, int position) {
    while (position > 0) {
        if (!heap->compare(heap->array->array[ParentIdx(position)], heap->array->array[position])) {
            return;
        }
        SwapValue(&heap->array->array[position], &heap->array->array[ParentIdx(position)]);
        position = (position - 1) / 2;
    }
}

static void ValuePushDown(Heap heap, int position) {
    while (true) {
        const int left_child_idx = position * 2 + 1;
        if (left_child_idx >= heap->size) {
            return;
        }
        if (left_child_idx + 1 >= heap->size) {
            if (heap->compare(heap->array->array[position], heap->array->array[left_child_idx])) {
                SwapValue(&heap->array->array[left_child_idx], &heap->array->array[position]);
            }
            return;
        }
        const int next_position_idx = heap->compare(heap->array->array[position * 2 + 1],
                                          heap->array->array[position * 2 + 2])
                                ? position * 2 + 2
                                : position * 2 + 1;
        if (heap->compare(heap->array->array[next_position_idx], heap->array->array[position])) {
            return;
        }
        SwapValue(&heap->array->array[next_position_idx], &heap->array->array[position]);
        position = next_position_idx;
    }
}

Heap NewHeap(Value value, int capacity, bool (*compare)(Value high_priority, Value low_priority)) {
    Heap heap = allocator_instance.allocate(sizeof(struct heap));
    *heap = (struct heap){
        .array = NewArray(capacity),
        .size = 1,
        .compare = compare,
    };
    heap->array->array[0] = value;
    return heap;
}

void InsertHeap(Heap heap, Value value) {
    const int size = heap->size;
    if (size == heap->array->capacity) {
        heap->array = ResizeArray(heap->array, size * 2);
    }
    heap->array->array[size] = value;
    ValuePushUp(heap, size);
    heap->size++;
}

Value TopHeap(Heap heap) {
    if (heap->size == 0) {
        return NULL;
    }
    return heap->array->array[0];
}

Value PopHeap(Heap heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty\n");
        exit(DE_EMPTY_QUEUE_FAIL);
    }
    Value ret = heap->array->array[0];
    heap->array->array[0] = heap->array->array[heap->size - 1];
    heap->array->array[heap->size - 1] = NULL;
    heap->size--;
    ValuePushDown(heap, 0);
    return ret;
}

void DeleteHeap(Heap heap) {
    DeleteArray(heap->array);
    allocator_instance.deallocate(heap);
}