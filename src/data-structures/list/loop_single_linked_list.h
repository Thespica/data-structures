#ifndef DATA_STRUCT_LOOP_SINGLE_LINKED_LIST_H
#define DATA_STRUCT_LOOP_SINGLE_LINKED_LIST_H

#include <stdbool.h>

#include "data-structures/util/nodes.h"

/**
 * The head of loop single linked list, which contains a head node with value of number of nodes
 */
typedef Node LoopSingleLinkedList;

/**
 * Construct a loop single linked list
 *
 *
 * @return Head pointer of loop single linked list
 */
LoopSingleLinkedList NewLSLL(void);

/**
 * Insert a new node at head
 *
 * @param head Head pointer of loop single linked list
 * @param value Pinter to actual value in heap
 */
void HeadInsertLSLL(LoopSingleLinkedList head, NodeValue value);

/**
 * Insert a new node at tail
 *
 * @param head Head pointer of loop single linked list
 * @param value Pinter to actual value in heap
 */
void TailInsertLSLL(LoopSingleLinkedList head, NodeValue value);

/**
 * Print loop single linked list
 *
 * @param head Head pointer of loop single linked list
 */
void PrintLSLL(LoopSingleLinkedList head);

/**
 * Delete the loop single linked list, set the loop single linked list holder to NULL after
 *
 * @param head Head pointer of loop single linked list
 */
void DeleteLSLL(LoopSingleLinkedList *head);

#endif //DATA_STRUCT_LOOP_SINGLE_LINKED_LIST_H
