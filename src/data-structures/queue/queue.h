/*
 * Copyright 2024 Thespica
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DATA_STRUCT_QUEUE_H
#define DATA_STRUCT_QUEUE_H

#include <stddef.h>

#include "data-structures/base/nodes.h"
#include "data-structures/list/single_linked_list.h"

/**
 * The queue, which contains a head node with value of number of nodes
 */
struct queue {
    SingleLinkedList head;
    Node tail;
};

/**
 * The queue as a whole, implemented by single linked list,
 * And the queue will always point to the head node.
 */
typedef struct queue* Queue;

/**
 * Construct a queue with head node
 *
 * @return Head pointer of queue
 */
Queue NewQueue(void);

/**
 * Insert a new node at tail of queue
 *
 * @param queue Head pointer of queue
 * @param value Pointer to actual value in heap
 */
void EnQueue(Queue queue, NodeValue value);

/**
 * Get and delete the first node of queue, the head node always exists.
 * The return value must be hold or free after.
 *
 * @param queue Head pointer of queue
 * @return Pointer to the actual value in heap, which must be hold or free
 */
NodeValue DeQueue(Queue queue);

/**
 * Get capacity of the queue
 *
 * @param queue Head pointer of queue
 * @return Size of the queue
 */
size_t GetQueueSize(Queue queue);

/**
 * Traverse the queue, the callback function will be called with each node
 *
 * @param queue Head pointer of queue
 */
void TraverseQueue(Queue queue, void (*for_traversing_node)(Node));

/**
 * Destruct the queue, suggest to set the original queue holder to NULL after
 *
 * @param queue Head pointer of queue
 */
void DeleteQueue(Queue queue);

#endif  // DATA_STRUCT_QUEUE_H
