#ifndef DATA_STRUCT_STACK_H
#define DATA_STRUCT_STACK_H

#include <stddef.h>

#include "data-structures/list/single_linked_list.h"
#include "data-structures/base/nodes.h"

/**
 * The stack as a whole, which always points to the head node
 */
typedef SingleLinkedList Stack;

/**
 * construct a stack
 *
 * @return Pointer of the stack
 */
Stack NewStack(void);

NodeValue TopStack(Stack stack);

/**
 * Push a new node at top of the stack
 *
 * @param stack Pointer of the stack
 * @param value Pointer to actual value in heap
 */
void PushStack(Stack stack, NodeValue value);

/**
 * Pop the top value of the stack, the return value must be hold or free
 *
 * @param stack Pointer of the stack
 * @return Pointer to the actual value in heap, which must be hold or free
 */
NodeValue PopStack(Stack stack);

/**
 * Get size of the stack
 *
 * @param stack Pointer of the stack
 * @return Size of the stack
 */
size_t GetStackSize(Stack stack);

/**
 * Traverse the stack from the top to bottom, the callback function will be called with each node
 *
 * @param stack Pointer of the stack
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void TraverseStack(Stack stack, void (*for_traversing_node)(Node));

/**
 * Destruct the stack, suggest to set the original holder to NULL after
 *
 * @param stack Pointer of the stack
 */
void DeleteStack(Stack stack);

#endif //DATA_STRUCT_STACK_H
