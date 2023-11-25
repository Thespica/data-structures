#include "data-structures/list/single_linked_list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "data-structures/util/allocator.h"
#include "data-structures/util/generic.h"

extern struct allocator allocator_instance;

SingleLinkedList NewSLL(void) {
    return NewNode(NewInt(0), NULL);
}

int GetNodesNumSLL(SingleLinkedList head) {
    return GetInt(head->value);
}

Node GetNodeAtSLL(SingleLinkedList head, size_t position) {
    if (position > GetInt(head->value)) {
        return NULL;
    }
    Node iter_node = head;
    for (int i = 0; i < position; i++) {
        iter_node = iter_node->next;
    }
    return iter_node;
}

void InsertNodeAtSLL(SingleLinkedList head, size_t position, NodeValue value) {
    if (position == 0) {
        DeleteNode(value);
        return;
    }
    if (position > GetInt(head->value) + 1) {
        position = GetInt(head->value) + 1;
    }
    Node front_node = GetNodeAtSLL(head, position - 1);
    Node new_node = NewNode(value, front_node->next);
    front_node->next = new_node;
    IntPostInc(head->value);
}

void HeadInsertSLL(SingleLinkedList head, NodeValue value) {
    InsertNodeAtSLL(head, 1, value);
}

void TailInsertSLL(SingleLinkedList head, NodeValue value) {
    InsertNodeAtSLL(head, GetNodesNumSLL(head) + 1, value);
}

void DeleteNodeAtSLL(SingleLinkedList head, size_t position) {
    if (!position || position > GetNodesNumSLL(head)) {
        return;
    }
    Node front_node = GetNodeAtSLL(head, position - 1);
    Node node_to_be_deleted = front_node->next;
    front_node->next = front_node->next->next;
    allocator_instance.deallocate(node_to_be_deleted);
    IntPostDec(head->value);
}

void TraverseSLL(SingleLinkedList head, void (*for_traversing_node)(Node)) {
    for (Node iter = head->next; iter; iter = iter->next) {
        for_traversing_node(iter);
    }
}

void DestructSLL(SingleLinkedList *list) {
    Node current = *list;
    while (current) {
        Node node_to_be_deleted = current;
        current = current->next;
        DeleteNode(node_to_be_deleted);
    }
    *list = NULL;
}