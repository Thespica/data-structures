#include <stdio.h>
#include <stdlib.h>

#include "data-structures/list/single_linked_list.h"

SingleLinkedList ConstructSLL(void) {
    Node *head = (Node *) malloc(sizeof(Node));
    head->value = 0;
    head->next = NULL;
    return head;
}

inline Node *GetNodeAtSLL(SingleLinkedList head, unsigned int position) {
    if (position > head->value) {
        return NULL;
    }
    Node *iter_node = head;
    for (int i = 0; i < position; i++) {
        iter_node = iter_node->next;
    }
    return iter_node;
}

void DeleteNodeAtSLL(SingleLinkedList head, unsigned int position) {
    if (!position || position > head->value) {
        return;
    }
    Node *front_node = GetNodeAtSLL(head, position - 1);
    Node *node_to_be_deleted = front_node->next;
    front_node->next = node_to_be_deleted->next;
    free(node_to_be_deleted);
    head->value--;
}

int GetNodesNumSLL(const SingleLinkedList head) {
    return head->value;
}

void InsertNodeAtSLL(SingleLinkedList head, unsigned int position, SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    if (position == 0) {
        return;
    }
    if (position > head->value + 1) {
        position = head->value + 1;
    }
    Node *front_node = GetNodeAtSLL(head, position - 1);
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = front_node->next;
    front_node->next = new_node;
    head->value++;
}

void TailInsertSLL(SingleLinkedList head, SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    InsertNodeAtSLL(head, head->value + 1, value);
}

void HeadInsertSLL(SingleLinkedList head, SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    InsertNodeAtSLL(head, 1, value);
}

void PrintSLL(SingleLinkedList head) {
    for (Node *iter = head->next; iter; iter = iter->next) {
        printf("%d ", iter->value);
    }
    printf("\n");
}

bool DeleteFirstValueInSLL(SingleLinkedList head, SINGLE_LINKED_LIST_ELEMENT_TYPE value) {
    Node *current = head;
    while (current->next) {
        if (current->next->value == value) {
            Node *node_to_be_deleted = current->next;
            current->next = current->next->next;
            free(node_to_be_deleted);
            head->value--;
            return true;
        }
        current = current->next;
    }
    return false;
}

void DestructSLL(SingleLinkedList *head) {
    Node *current = *head;
    while (current) {
        Node *node_to_be_deleted = current;
        current = current->next;
        free(node_to_be_deleted);
    }
    *head = NULL;
}