#include "data-structures/base/array.h"

#include "data-structures/memory/allocator.h"
#include "data-structures/util/error_code.h"

extern struct allocator allocator_instance;

Array NewArray(size_t size) {
    Array new_array =
        (Array)allocator_instance.allocate(sizeof(struct array) + size * sizeof(Value));
    if (!new_array) {
        fprintf(stderr, "NewArray alloc memory fatal.\n");
        exit(OOM_FAIL);
    }
    new_array->capacity = size;
    for (int i = 0; i < size; i++) {
        new_array->array[i] = NULL;
    }
    return new_array;
}

size_t GetSizeArray(Array array) { return array->capacity; }

Array ResizeArray(Array array, size_t new_array_size) {
    Array new_array = (Array)allocator_instance.reallocate(
        array, sizeof(struct array) + new_array_size * sizeof(Value));
    if (!new_array) {
        fprintf(stderr, "ResizeArray realloc memory fatal.\n");
        exit(OOM_FAIL);
    }
    if (new_array_size <= array->capacity) {
        new_array->capacity = new_array_size;
        return new_array;
    }
    for (int i = array->capacity; i < new_array_size; i++) {
        new_array->array[i] = NULL;
    }
    array->capacity = new_array_size;
    return new_array;
}

Value GetValueAtArray(Array array, size_t position) {
    if (position >= array->capacity) {
        fprintf(stderr, "GetValueAtArray position out of range.\n");
        exit(OUT_OF_RANGE_FAIL);
    }
    return array->array[position];
}

Value ReplaceValueAtArray(Array array, size_t position, Value value) {
    if (position >= array->capacity) {
        fprintf(stderr, "ReplaceValueAtArray position out of range.\n");
        exit(OUT_OF_RANGE_FAIL);
    }
    Value ret_value = array->array[position];
    array->array[position] = value;
    return ret_value;
}

void DeleteArray(Array array) { allocator_instance.deallocate(array); }