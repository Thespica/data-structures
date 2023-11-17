#include <stdio.h>
#include <stdlib.h>

#include "data-structures/list/loop_single_linked_list.h"

LoopSingleLinkedList ConstructLSLL(void) {
    Node *head = (Node *) malloc(sizeof(Node));
    head->value = 0;
    head->next = head;
    return head;
}

void HeadInsertLSLL(LoopSingleLinkedList head, LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = head->next;
    head->next = new_node;
    head->value++;
}

*/
void TailInsertLSLL(LoopSingleLinkedList head, LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *iter = head;
    while (iter->next != head) {
        iter = iter->next;
    }
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = head;
    iter->next = new_node;
}

bool DeleteFirstValueInLSLL(LoopSingleLinkedList head, LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *iter = head;
    while (iter->next != head) {
        if (iter->next->value == value) {
            Node *node_to_be_deleted = iter->next;
            iter->next = iter->next->next;
            free(node_to_be_deleted);
            return true;
        }
    }
    return false;
}

void PrintLSLL(LoopSingleLinkedList head) {
    for (Node *iter = head->next; iter != head; iter = iter->next) {
        printf("%d ", iter->value);
    }
    putchar('\n');
}

void DestructLSLL(LoopSingleLinkedList head) {
    Node *iter = head->next;
    while (iter != head) {
        Node *node_to_be_deleted = iter;
        iter = iter->next;
        free(node_to_be_deleted);
    }
    free(head);
}