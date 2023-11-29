#include "data-structures/list/single_linked_list.h"

#include <stddef.h>

#include "data-structures/memory/allocator.h"
#include "data-structures/util/generic.h"

extern struct allocator allocator_instance;

SingleLinkedList NewSLL(void) { return NewNode(NewInt(0), NULL); }

size_t GetSizeSLL(SingleLinkedList head) { return GetInt(head->value); }

Node GetNodeAtSLL(SingleLinkedList head, size_t position) {
    if (position >= GetSizeSLL(head)) {
        return NULL;
    }
    Node iter_node = head->next;
    for (int i = 0; i < position; i++) {
        iter_node = iter_node->next;
    }
    return iter_node;
}

void InsertNodeAtSLL(SingleLinkedList head, size_t position, NodeValue value) {
    if (position >= GetInt(head->value)) {
        position = GetInt(head->value);
    }
    Node front_node = position ? GetNodeAtSLL(head, position - 1) : head;
    Node new_node = NewNode(value, front_node->next);
    front_node->next = new_node;
    IntPostInc(head->value);
}

void HeadInsertSLL(SingleLinkedList head, NodeValue value) {
    InsertNodeAtSLL(head, 0, value);
}

void TailInsertSLL(SingleLinkedList head, NodeValue value) {
    InsertNodeAtSLL(head, GetSizeSLL(head), value);
}

NodeValue ReplaceNodeValueAtSLL(SingleLinkedList head, size_t position,
                                NodeValue value) {
    if (!position || position > GetSizeSLL(head)) {
        return NULL;
    }
    Node node = GetNodeAtSLL(head, position);
    NodeValue ret_value = node->value;
    node->value = value;
    return ret_value;
}

NodeValue MoveNodeValueAtSLL(SingleLinkedList head, size_t position) {
    if (position >= GetSizeSLL(head)) {
        return NULL;
    }
    Node front_node = position ? head : GetNodeAtSLL(head, position);
    Node node_to_be_moved = front_node->next;
    front_node->next = front_node->next->next;
    IntPostDec(head->value);
    return MoveNodeValue(node_to_be_moved);
}

void DeleteNodeAtSLL(SingleLinkedList head, size_t position) {
    if (!position || position > GetSizeSLL(head)) {
        return;
    }
    Node front_node = GetNodeAtSLL(head, position - 1);
    Node node_to_be_deleted = front_node->next;
    front_node->next = front_node->next->next;
    IntPostDec(head->value);
    DeleteNode(node_to_be_deleted);
}

void TraverseSLL(SingleLinkedList head, void (*for_traversing_node)(Node)) {
    for (Node iter = head->next; iter; iter = iter->next) {
        for_traversing_node(iter);
    }
}

void DeleteSLL(SingleLinkedList list) {
    while (list) {
        Node node_to_be_deleted = list;
        list = list->next;
        DeleteNode(node_to_be_deleted);
    }
}