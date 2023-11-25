#ifndef DATA_STRUCT_LOOP_DOUBLE_LINKED_LIST_H
#define DATA_STRUCT_LOOP_DOUBLE_LINKED_LIST_H

#include <stdbool.h>

#ifndef LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE
#define LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE int
#endif

/**
 * The node of loop double linked list
 */
typedef struct node {
    LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value;
    struct node *prev;
    struct node *next;
} Node;

/**
 * The head of loop double linked list, which contains a head node with value of number of nodes
 */
typedef Node * LoopDoubleLinkedList;

/**
 * Construct a loop double linked list
 *
 * @return Head pointer of loop double linked list
 */
LoopDoubleLinkedList ConstructDLL(void);

/**
 * Insert a new node at head
 *
 * @param head Head pointer of loop double linked list
 * @param value Value of new node
 */
void HeadInsertLDLL(LoopDoubleLinkedList head, LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Insert a new node at tail
 *
 * @param head Head pointer of loop double linked list
 * @param value Value of new node
 */
void TailInsertLDLL(LoopDoubleLinkedList head, LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Delete the first node with value
 *
 * @param head Head pointer of loop double linked list
 * @param value Value of node to be deleted
 * @return
 */
bool DeleteFirstValueInLDLL(LoopDoubleLinkedList head, LOOP_DOUBLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Print loop double linked list
 *
 * @param head Head pointer of loop double linked list
 */
void PrintLDLL(LoopDoubleLinkedList head);

/**
 * Delete the loop double linked list
 *
 * @param head Head pointer of loop double linked list
 */
void DestructLDLL(LoopDoubleLinkedList head);

#endif //DATA_STRUCT_LOOP_DOUBLE_LINKED_LIST_H
