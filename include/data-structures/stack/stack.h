#ifndef DATA_STRUCT_STACK_H
#define DATA_STRUCT_STACK_H

#include <stddef.h>

#ifndef STACK_ELEMENT_TYPE
#define STACK_ELEMENT_TYPE int
#endif
#define SINGLE_LINKED_LIST_ELEMENT_TYPE STACK_ELEMENT_TYPE
#include "data-structures/list/single_linked_list.h"
#define POP_EMPTY_STACK_FAIL 4
#define PUSH_FULL_STACK_FAIL (POP_EMPTY_STACK_FAIL+1)

/**
 * @brief The stack in memory, implemented by single linked list
 */
typedef SingleLinkedList Stack;

/**
 * @brief construct a stackf
 * @return Pointer of the stack
 */
Stack ConstructStack(void);

/**
 * @brief Push a new node at top of the stack
 * @param stack Pointer of the stack
 * @param value Value of new value
 */
void PushStack(Stack stack, STACK_ELEMENT_TYPE value);

/**
 * @brief Pop the top value of the stack
 * @param stack Pointer of the stack
 * @return Value of the top element in the stack
 */
STACK_ELEMENT_TYPE PopStack(Stack stack);

/**
 * @brief Get size of the stack
 * @param stack Pointer of the stack
 * @return Size of the stack
 */
size_t GetStackSize(Stack stack);

/**
 * @brief Print the stack from top to bottom
 * @param stack Pointer of the stack
 */
void PrintStack(Stack stack);

/**
 * @brief Destruct the stack
 * @param stack Pointer of the stack on the stack, set to NULL after
 */
void DestructStack(Stack *stack);

#endif //DATA_STRUCT_STACK_H
