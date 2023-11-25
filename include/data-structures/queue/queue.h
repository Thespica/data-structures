#ifndef DATA_STRUCT_QUEUE_H
#define DATA_STRUCT_QUEUE_H

#include <stddef.h>

#include "../util/nodes.h"

/**
 * The queue, which contains a head node with value of number of nodes
 */
struct queue {
    struct node *head;
    struct node *tail;
};

/**
 * The queue as a whole, implemented by single linked list,
 * And the queue will always point to the head node.
 */
typedef struct queue * Queue;

/**
 * Construct a queue with head node
 * 
 * @return Head pointer of queue
 */
Queue NewQueue(void);

/**
 * Insert a new node at tail of queue
 */
void EnQueue(Queue queue, QUEUE_ELEMENT_TYPE value);

/**
 * Get and delete the first node of queue, the head node always exists
 * 
 * @param queue Head pointer of queue
 * @return Value of first node
 */
QUEUE_ELEMENT_TYPE DeQueue(Queue queue);

/**
 * Get size of the queue
 * 
 * @param queue Head pointer of queue
 * @return Size of the queue
 */
size_t GetQueueSize(Queue queue);

/**
 * Print the queue
 * 
 * @param queue Head pointer of queue
 */
void PrintQueue(Queue queue);

/**
 * Destruct the queue, the queue holder will be set to NULL after
 * 
 * @param queue Head pointer of queue
 */
void DestructQueue(Queue *queue);

#endif //DATA_STRUCT_QUEUE_H
