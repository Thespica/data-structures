#ifndef DATA_STRUCT_QUEUE_H
#define DATA_STRUCT_QUEUE_H

#include <stddef.h>

#define QUEUE_ELEMENT_TYPE int
#define DE_EMPTY_QUEUE_FAIL 2

/**
 * @brief The node of queue
 */
typedef struct node {
    QUEUE_ELEMENT_TYPE value;
    struct node *next;
} Node;

/**
 * @brief The queue, which contains a head node with value of number of nodes
 */
struct queue {
    Node *head;
    Node *tail;
};

/**
 * @brief The queue as pointer
 */
typedef struct queue * Queue;

/**
 * @brief Construct a queue with head node
 * @return Head pointer of queue
 */
Queue ConstructQueue(void);

/**
 * @brief Insert a new node at tail of queue
 */
void Enqueue(Queue queue, QUEUE_ELEMENT_TYPE value);

/**
 * @brief Get and delete the first node of queue
 * @param queue Head pointer of queue
 * @return Value of first node
 */
QUEUE_ELEMENT_TYPE Dequeue(Queue queue);

/**
 * @brief Get size of the queue
 * @param queue Head pointer of queue
 * @return Size of the queue
 */
size_t GetQueueSize(Queue queue);

/**
 * @brief Print the queue
 * @param queue Head pointer of queue
 */
void PrintQueue(Queue queue);

/**
 * @brief Destruct the queue, the queue holder will be set to NULL after
 * @param queue Head pointer of queue
 */
void DestructQueue(Queue *queue);

#endif //DATA_STRUCT_QUEUE_H
