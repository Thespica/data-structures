#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

#include "../util/nodes.h"

typedef Node SingleLinkedList;

/**
 * Construct a single linked list
 *
 * @return Head pointer of single linked list
 */
SingleLinkedList NewSLL(void);

/**
 * Get number of nodes
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 * @return Number of nodes
 */
int GetNodesNumSLL(SingleLinkedList head);

/**
 * Get node at position
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 * @return Node pointer
 */
Node GetNodeAtSLL(SingleLinkedList head, size_t position);

/**
 * Insert a node at position, begin with 1
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 * @param value Value of node to be inserted
 */
void InsertNodeAtSLL(SingleLinkedList head, size_t position, NodeValue value);

/**
 * Insert a new node at head
 *
 * @param head Head pointer of single linked list
 * @param value Value of node to be inserted
 */
void HeadInsertSLL(SingleLinkedList head, NodeValue value);

/**
 * Insert a new node at tail
 *
 * @param head Head pointer of single linked list
 * @param value Value of node to be inserted
 */
void TailInsertSLL(SingleLinkedList head, NodeValue value);

/**
 * Delete node at position
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 */
void DeleteNodeAtSLL(SingleLinkedList head, size_t position);

/**
 * Traverse the single linked list
 * @param head Head pointer of single linked list
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void TraverseSLL(SingleLinkedList head, void (*for_traversing_node)(Node));

/**
 * Delete the single linked list, set the holder to NULL after
 *
 * @param list Pointer of the single linked list holder
 */
void DeleteSLL(SingleLinkedList *list);

#endif // SINGLE_LINKED_LIST_H