#include <stdio.h>
#include <stdlib.h>

#include "data-structures/queue/queue.h"

Queue ConstructQueue(void) {
    Queue queue = (Queue) malloc(sizeof(struct queue));
    Node *head_node = (Node *) malloc(sizeof(Node));
    head_node->value = 0;
    head_node->next = NULL;
    queue->head = head_node;
    queue->tail = head_node;
    return queue;
}

void Enqueue(Queue queue, QUEUE_ELEMENT_TYPE value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    queue->tail->next = new_node;
    queue->tail = new_node;
    queue->head->value++;
}

QUEUE_ELEMENT_TYPE Dequeue(Queue queue) {
    if (GetQueueSize(queue) == 0) {
        fprintf(stderr, "Error: queue is empty\n");
        exit(DE_EMPTY_QUEUE_FAIL);
    }
    Node *node_to_delete = queue->head->next;
    QUEUE_ELEMENT_TYPE value = node_to_delete->value;
    queue->head->next = node_to_delete->next;
    free(node_to_delete);
    queue->head->value--;
    return value;
}

size_t GetQueueSize(Queue queue) {
    return queue->head->value;
}

void PrintQueue(Queue queue) {
    for (Node *iter = queue->head->next; iter; iter = iter->next) {
        printf("%d ", iter->value);
    }
    putchar('\n');
}

void DestructQueue(Queue *queue) {
    Queue queue_to_delete = *queue;
    *queue = NULL;
    Node *iter = queue_to_delete->head;
    while (iter) {
        Node *node_to_delete = iter;
        iter = iter->next;
        free(node_to_delete);
    }
    free(queue_to_delete);
}
