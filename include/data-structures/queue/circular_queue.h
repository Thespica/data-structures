#ifndef DATA_STRUCT_CIRCULAR_QUEUE_H
#define DATA_STRUCT_CIRCULAR_QUEUE_H

#include <stddef.h>

#define CIRCULAR_QUEUE_ELEMENT_TYPE int
#define DE_EMPTY_QUEUE_FAIL 2
#define EN_FULL_CIRCULAR_QUEUE_FAIL 3

/**
 * @brief The circular queue in memory
 */
typedef struct circular_queue {
    CIRCULAR_QUEUE_ELEMENT_TYPE *array;
    size_t head_idx;
    size_t tail_idx;
    size_t capacity;
} circular_queue;

/**
 * @brief The circular queue as pointer
 */
typedef struct circular_queue * CircularQueue;

/**
 * @brief Construct a circular queue
 * @param capacity Capacity of the circular queue
 * @return Pointer of the circular queue
 */
CircularQueue ConstructCircularQueue(size_t capacity);

/**
 * @brief Insert a new node at tail of the circular queue
 * @param circular_queue Pointer of the circular queue
 * @param value Value of new value
 */
void EnCircularQueue(CircularQueue circular_queue, CIRCULAR_QUEUE_ELEMENT_TYPE value);

/**
 * @brief Get the first value of the circular queue
 * @param circular_queue Pointer of the circular queue
 * @return Value of the first element in the circular queue
 */
CIRCULAR_QUEUE_ELEMENT_TYPE DeCircularQueue(CircularQueue circular_queue);

/**
 * @brief Get size of the circular queue
 * @param circular_queue Pointer of the circular queue
 * @return Size of the circular queue
 */
size_t GetCircularQueueSize(CircularQueue circular_queue);

/**
 * @brief Print the circular queue
 * @param circular_queue Pointer of the circular queue
 */
void PrintCircularQueue(CircularQueue circular_queue);

/**
 * @brief Delete the circular queue, and set the pointer to NULL after
 * @param circular_queue Pointer of the circular queue
 */
void DestroyCircularQueue(CircularQueue *circular_queue);

#endif //DATA_STRUCT_CIRCULAR_QUEUE_H
