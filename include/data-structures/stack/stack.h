#ifndef DATA_STRUCT_STACK_H
#define DATA_STRUCT_STACK_H

#include <stddef.h>

#define STACK_ELEMENT_TYPE int
#define POP_EMPTY_STACK_FAIL 4
#define PUSH_FULL_STACK_FAIL POP_EMPTY_STACK_FAIL + 1

/**
 * @brief The stack in memory
 */
struct stack {
    STACK_ELEMENT_TYPE *array;
    size_t top_idx;
    size_t capacity;
};

/**
 * @brief The stack as pointer, top_idx is -1 when stack is empty
 */
typedef struct stack * Stack;

/**
 * @brief Construct a stack
 * @param capacity Capacity of the stack
 * @return Pointer of the stack
 */
Stack ConstructStack(size_t capacity);

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
 * @brief Destruct the stack, and set the pointer to NULL after
 * @param stack Pointer of the pointer to stack
 */
void DestructStack(Stack *stack);

#endif //DATA_STRUCT_STACK_H
