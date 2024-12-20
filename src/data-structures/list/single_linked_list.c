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

#include "data-structures/list/single_linked_list.h"

#include <stddef.h>

#include "data-structures/memory/allocator.h"
#include "data-structures/util/generic.h"
#include "data-structures/util/error_code.h"

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
    if (head == NULL || head->value == NULL || position > GetInt(head->value)) {
        fprintf(stderr, "Insertion to single linked list failed!\n");
        exit(OUT_OF_RANGE_FAIL);
    }
    Node front_node = position ? GetNodeAtSLL(head, position - 1) : head;
    Node new_node = NewNode(value, front_node->next);
    front_node->next = new_node;
    IntPostInc(head->value);
}

void HeadInsertSLL(SingleLinkedList head, NodeValue value) { InsertNodeAtSLL(head, 0, value); }

void TailInsertSLL(SingleLinkedList head, NodeValue value) {
    InsertNodeAtSLL(head, GetSizeSLL(head), value);
}

NodeValue ReplaceNodeValueAtSLL(SingleLinkedList head, size_t position, NodeValue value) {
    if (!position || position > GetSizeSLL(head)) {
        return NULL;
    }
    Node node = GetNodeAtSLL(head, position);
    if (!node) {
        return NULL;
    }
    NodeValue ret_value = node->value;
    node->value = value;
    return ret_value;
}

NodeValue MoveNodeValueAtSLL(SingleLinkedList head, size_t position) {
    if (position >= GetSizeSLL(head)) {
        return NULL;
    }
    Node front_node = position ? GetNodeAtSLL(head, position) : head;
    Node node_to_be_moved = front_node->next;
    front_node->next = front_node->next->next;
    IntPostDec(head->value);
    return MoveNodeValue(node_to_be_moved);
}

NodeValue PopHeadSLL(SingleLinkedList head) { return MoveNodeValueAtSLL(head, 0); }

void DeleteNodeAtSLL(SingleLinkedList head, size_t position) {
    if (!position || position > GetSizeSLL(head)) {
        return;
    }
    Node front_node = GetNodeAtSLL(head, position - 1);
    if (!front_node) {
        return;
    }
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