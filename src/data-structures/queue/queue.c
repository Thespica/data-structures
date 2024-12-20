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

#include "data-structures/queue/queue.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/base/nodes.h"
#include "data-structures/list/single_linked_list.h"
#include "data-structures/memory/allocator.h"
#include "data-structures/util/error_code.h"
#include "data-structures/util/generic.h"

extern struct allocator allocator_instance;

Queue NewQueue(void) {
    Queue queue = (Queue)allocator_instance.allocate(sizeof(struct queue));
    queue->head = NewSLL();
    queue->tail = queue->head;
    return queue;
}

void EnQueue(Queue queue, NodeValue value) { TailInsertSLL(queue->tail, value); }

NodeValue DeQueue(Queue queue) {
    if (GetQueueSize(queue) == 0) {
        fprintf(stderr, "Error: queue is empty\n");
        exit(DE_EMPTY_QUEUE_FAIL);
    }
    Node node_to_delete = GetNodeAtSLL(queue->head, 0);
    queue->head->next = queue->head->next->next;
    NodeValue value = node_to_delete->value;
    IntPostDec(queue->head->value);
    allocator_instance.deallocate(node_to_delete);
    return value;
}

size_t GetQueueSize(Queue queue) { return GetSizeSLL(queue->head); }

void TraverseQueue(Queue queue, void (*for_traversing_node)(Node)) {
    TraverseSLL(queue->head, for_traversing_node);
}

void DeleteQueue(Queue queue) {
    DeleteSLL(queue->head);
    allocator_instance.deallocate(queue);
}