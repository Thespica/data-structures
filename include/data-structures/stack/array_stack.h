#ifndef DATA_STRUCT_ARRAY_STACK_H
#define DATA_STRUCT_ARRAY_STACK_H

#include <stddef.h>

#ifndef STACK_ELEMENT_TYPE
#define STACK_ELEMENT_TYPE int
#endif
#define POP_EMPTY_STACK_FAIL 4
#define PUSH_FULL_STACK_FAIL (POP_EMPTY_STACK_FAIL+1)

/**
 * The array_stack in memory
 */
struct array_stack {
    STACK_ELEMENT_TYPE *array;
    size_t top_idx;
    size_t capacity;
};

/**
 * The array_stack as pointer, top_idx is -1 when array_stack is empty
 */
typedef struct array_stack * ArrayStack;

/**
 * Construct a array_stack
 *
 * @param capacity Capacity of the array_stack
 * @return Pointer of the array_stack
 */
ArrayStack ConstructStack(size_t capacity);

/**
 * Push a new node at top of the array_stack
 *
 * @param stack Pointer of the array_stack
 * @param value Value of new value
 */
void PushStack(ArrayStack stack, STACK_ELEMENT_TYPE value);

/**
 * Pop the top value of the array_stack
 *
 * @param stack Pointer of the array_stack
 * @return Value of the top element in the array_stack
 */
STACK_ELEMENT_TYPE PopStack(ArrayStack stack);

/**
 * Get size of the array_stack
 *
 * @param stack Pointer of the array_stack
 * @return Size of the array_stack
 */
size_t GetStackSize(ArrayStack stack);

/**
 * Print the array_stack from top to bottom
 *
 * @param stack Pointer of the array_stack
 */
void PrintStack(ArrayStack stack);

/**
 * Destruct the array_stack, and set the pointer to NULL after
 *
 * @param stack Pointer of the pointer to array_stack
 */
void DestructStack(ArrayStack *stack);

#endif //DATA_STRUCT_ARRAY_STACK_H
