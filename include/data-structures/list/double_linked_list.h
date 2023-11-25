#ifndef DATA_STRUCT_DOUBLE_LINKED_LIST_H
#define DATA_STRUCT_DOUBLE_LINKED_LIST_H

#include <stdbool.h>

#ifndef DOUBLE_LINKED_LIST_ELEMENT_TYPE
#define DOUBLE_LINKED_LIST_ELEMENT_TYPE int
#endif

/**
 * The node of double linked list
 */
typedef struct node {
    DOUBLE_LINKED_LIST_ELEMENT_TYPE value;
    struct node *prev;
    struct node *next;
} Node;

/**
 * The head of double linked list, which contains a head node with value of number of nodes
 */
typedef Node * DoubleLinkedList;

/**
 * Construct a double linked list
 *
 * @return Head pointer of double linked list
 */
DoubleLinkedList ConstructDLL(void);

/**
 * Insert a new node at head
 *
 * @param head Head pointer of double linked list
 * @param value Value of new node
 */
void HeadInsertDLL(DoubleLinkedList head, DOUBLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Insert a new node at tail
 *
 * @param head Head pointer of double linked list
 * @param value Value of new node
 */
void TailInsertDLL(DoubleLinkedList head, DOUBLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Delete the first node with value
 *
 * @param head Head pointer of double linked list
 * @param value Value of node to be deleted
 * @return
 */
bool DeleteFirstValueInDLL(DoubleLinkedList head, DOUBLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Print double linked list
 *
 * @param head Head pointer of double linked list
 */
void PrintDLL(DoubleLinkedList head);

/**
 * Delete the double linked list, and set the pointer on array_stack to NULL after
 *
 * @param head Head pointer of double linked list
 */
void DestructDLL(DoubleLinkedList *head);

#endif //DATA_STRUCT_DOUBLE_LINKED_LIST_H
