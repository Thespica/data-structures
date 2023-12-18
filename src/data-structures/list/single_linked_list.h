#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stddef.h>

#include "data-structures/base/nodes.h"

/**
 * The single linked list as a whole, which always points to the head node
 */
typedef Node SingleLinkedList;

/**
 * Construct a single linked list
 *
 * @return Head pointer of single linked list
 */
SingleLinkedList NewSLL(void);

/**
 * Get capacity of the single linked list
 *
 * @param head Head pointer of single linked list
 * @return Number of nodes
 */
size_t GetSizeSLL(SingleLinkedList head);

/**
 * Get node at position, not include head node, begin with 0
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 0
 * @return Node pointer
 */
Node GetNodeAtSLL(SingleLinkedList head, size_t position);

/**
 * Insert a node at position, begin with 0
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 0
 * @param value Pointer to actual value in heap
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
 * Replace node value at position, the original value must be hold or free
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 0
 * @param value Pointer to actual value in heap
 * @return Pointer to the original value, which must be hold or free
 */
NodeValue ReplaceNodeValueAtSLL(SingleLinkedList head, size_t position, NodeValue value);

/**
 * Move node value at position, the node itself will be free.
 * The value must be hold or free after.
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 0
 * @return Pointer to the actual value in heap, which must be hold or free
 */
NodeValue MoveNodeValueAtSLL(SingleLinkedList head, size_t position);

NodeValue PopHeadSLL(SingleLinkedList head);

/**
 * Delete node at position
 *
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 0
 */
void DeleteNodeAtSLL(SingleLinkedList head, size_t position);

/**
 * Traverse the single linked list
 *
 * @param head Head pointer of single linked list
 * @param for_traversing_node Function pointer to process each node when
 * traversing
 */
void TraverseSLL(SingleLinkedList head, void (*for_traversing_node)(Node));

/**
 * Delete the single linked list, suggest to set the original list holder to
 * NULL after
 *
 * @param list Pointer to the single linked list in heap
 */
void DeleteSLL(SingleLinkedList list);

#endif  // SINGLE_LINKED_LIST_H