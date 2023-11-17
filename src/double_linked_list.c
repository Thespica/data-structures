#include <stdio.h>
#include <stdlib.h>

#include "data-structures/list//double_linked_list.h"

DoubleLinkedList ConstructDLL(void) {
    DoubleLinkedList head = (DoubleLinkedList) malloc(sizeof(Node));
    head->value = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

void HeadInsertDLL(DoubleLinkedList head, DOUBLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = head;
    new_node->next = head->next;
    head->next = new_node;
    if (head->next) {
        new_node->next->prev = new_node;
    }
    head->value++;
}

void TailInsertDLL(DoubleLinkedList head, DOUBLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    Node *latest_node = head;
    while (latest_node->next) {
        latest_node = latest_node->next;
    }
    new_node->prev = latest_node;
    new_node->next = latest_node->next;
    latest_node->next = new_node;
    head->value++;
}

bool DeleteFirstValueInDLL(DoubleLinkedList head, DOUBLE_LINKED_LIST_ELEMENT_TYPE value) {
    for (Node *iter = head->next; iter != head; iter = iter->next) {
        if (iter->value != value) {
            continue;
        }
        Node *node_to_delete = iter;
        node_to_delete->prev->next = node_to_delete->next;
        if (!node_to_delete->next) {
            node_to_delete->next->prev = node_to_delete->prev;
        }
        free(node_to_delete);
        head->value--;
        return true;
    }
    return false;
}

void PrintDLL(DoubleLinkedList head) {
    for (Node *iter = head->next; iter != head; iter = iter->next) {
        printf("%d ", iter->value);
    }
    putchar('\n');
}

void DestructDLL(DoubleLinkedList *head) {
    Node *iter = *head;
    while (iter) {
        Node *node_to_delete = iter;
        iter = iter->next;
        free(node_to_delete);
    }
    *head = NULL;
}