#ifndef DATA_STRUCT_LOOP_SINGLE_LINKED_LIST_H
#define DATA_STRUCT_LOOP_SINGLE_LINKED_LIST_H

#include <stdbool.h>

#ifndef LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE
#define LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE int
#endif

/**
 * The node of loop single linked list
 */
typedef struct node {
    LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value;
    struct node *next;
} Node;

/**
 * The head of loop single linked list, which contains a head node with value of number of nodes
 */
typedef Node * LoopSingleLinkedList;

/**
 * Construct a loop single linked list
 *
 *
 * @return Head pointer of loop single linked list
 */
LoopSingleLinkedList ConstructLSLL(void);

/**
 * Insert a new node at head
 *
 * @param head Head pointer of loop single linked list
 * @param value Value of new node
 */
void HeadInsertLSLL(LoopSingleLinkedList head, LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Insert a new node at tail
 *
 * @param head Head pointer of loop single linked list
 * @param value Value of new node
 */
void TailInsertLSLL(LoopSingleLinkedList head, LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Insert a new node at tail
 *
 * @param head Head pointer of loop single linked list
 * @param value Value of new node
 * @return True if success, otherwise false
 */
bool DeleteFirstValueInLSLL(LoopSingleLinkedList head, LOOP_SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * Print loop single linked list
 *
 * @param head Head pointer of loop single linked list
 */
void PrintLSLL(LoopSingleLinkedList head);

/**
 * Delete the loop single linked list
 *
 * @param head Head pointer of loop single linked list
 */
void DestructLSLL(LoopSingleLinkedList head);

#endif //DATA_STRUCT_LOOP_SINGLE_LINKED_LIST_H
