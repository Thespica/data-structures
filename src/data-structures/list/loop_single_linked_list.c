#include "data-structures/list/loop_single_linked_list.h"

#include <stdio.h>

#include "data-structures/util/allocator.h"
#include "data-structures/util/generic.h"
#include "data-structures/util/nodes.h"

extern struct allocator allocator_instance;

LoopSingleLinkedList ConstructLSLL(void) {
    Node init_node = NewNode(NewInt(0), NULL);
    init_node->next = init_node;
}

void HeadInsertLSLL(LoopSingleLinkedList head, NodeValue value) {
    Node new_node = NewNode(value, head->next);
    head->next = new_node;
    IntPostInc(head->value);
}

void TailInsertLSLL(LoopSingleLinkedList head, NodeValue value) {
    Node iter = head;
    while (iter->next != head) {
        iter = iter->next;
    }
    Node new_node = NewNode(value, head);
    iter->next = new_node;
}

void PrintLSLL(LoopSingleLinkedList head) {
    for (Node iter = head->next; iter != head; iter = iter->next) {
        printf("%d ", iter->value);
    }
    putchar('\n');
}

void DeleteLSLL(LoopSingleLinkedList *head) {
    LoopSingleLinkedList original_list = *head;
    Node iter = original_list->next;
    while (iter != original_list) {
        Node node_to_be_deleted = iter;
        iter = iter->next;
        allocator_instance.deallocate(node_to_be_deleted);
    }
    allocator_instance.deallocate(original_list);
    head = NULL;
}