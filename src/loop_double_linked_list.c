#include <stdio.h>
#include <stdlib.h>

#include "data-structures/list/loop_double_linked_list.h"

LoopDoubleLinkedList ConstructLDLL(void) {
    LoopDoubleLinkedList head = (LoopDoubleLinkedList) malloc(sizeof(Node));
    head->value = 0;
    head->prev = head;
    head->next = head;
    return head;
}

void HeadInsertLDLL(LoopDoubleLinkedList head, LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = head;
    new_node->next = head->next;
    head->next = new_node;
    new_node->next->prev = new_node;
    head->value++;
}

void TailInsertLDLL(LoopDoubleLinkedList head, LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value) {
    HeadInsertLDLL(head->prev, value);
}

bool DeleteFirstValueInLDLL(LoopDoubleLinkedList head, LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value) {
    for (Node *iter = head->next; iter != head; iter = iter->next) {
        if (iter->value == value) {
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;
            free(iter);
            head->value--;
            return true;
        }
    }
    return false;
}

void PrintLDLL(LoopDoubleLinkedList head) {
    for (Node *iter = head->next; iter; iter = iter->next) {
        printf("%d ", iter->value);
    }
    putchar('\n');
}

void DestructLDLL(LoopDoubleLinkedList head) {
    for (Node *iter = head->next; iter != head; iter = iter->next) {
        Node *node_to_delete = iter;
        iter = iter->prev;
        free(node_to_delete);
    }
    free(head);
}