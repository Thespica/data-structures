#include <stdio.h>
#include <stdlib.h>

#include "data-structures/queue/circular_queue.h"

CircularQueue ConstructCircularQueue(size_t capacity) {
    CircularQueue circular_queue = (CircularQueue) malloc(sizeof(circular_queue));
    circular_queue->array = (CIRCULAR_QUEUE_ELEMENT_TYPE *) malloc(sizeof(CIRCULAR_QUEUE_ELEMENT_TYPE) * capacity);
    circular_queue->head_idx = 0;
    circular_queue->tail_idx = 0;
    circular_queue->capacity = capacity;
    return circular_queue;
}

void EnCircularQueue(CircularQueue circular_queue, CIRCULAR_QUEUE_ELEMENT_TYPE value) {
    if (GetCircularQueueSize(circular_queue) == circular_queue->capacity) {
        fprintf(stderr, "Error: circular queue is full\n");
        exit(EN_FULL_CIRCULAR_QUEUE_FAIL);
    }
    circular_queue->array[circular_queue->tail_idx] = value;
    circular_queue->tail_idx = (circular_queue->tail_idx + 1) % circular_queue->capacity;
}

CIRCULAR_QUEUE_ELEMENT_TYPE DeCircularQueue(CircularQueue circular_queue) {
    if (GetCircularQueueSize(circular_queue) == 0) {
        fprintf(stderr, "Error: circular queue is empty\n");
        exit(DE_EMPTY_QUEUE_FAIL);
    }
    CIRCULAR_QUEUE_ELEMENT_TYPE value = circular_queue->array[circular_queue->head_idx];
    circular_queue->head_idx = (circular_queue->head_idx + 1) % circular_queue->capacity;
    return value;
}

size_t GetCircularQueueSize(CircularQueue circular_queue) {
    return (circular_queue->tail_idx - circular_queue->head_idx + circular_queue->capacity) % circular_queue->capacity;
}

void PrintCircularQueue(CircularQueue circular_queue) {
    for (size_t i = circular_queue->head_idx; i != circular_queue->tail_idx; i = (i + 1) % circular_queue->capacity) {
        printf("%d ", circular_queue->array[i]);
    }
    putchar('\n');
}

void DestroyCircularQueue(CircularQueue *circular_queue) {
    CircularQueue circular_queue_to_delete = *circular_queue;
    *circular_queue = NULL;
    free(circular_queue_to_delete->array);
    free(circular_queue_to_delete);
}
