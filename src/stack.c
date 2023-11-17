#include <stdio.h>
#include <stdlib.h>

#include "data-structures/stack/stack.h"

Stack ConstructStack(size_t capacity) {
Stack stack = (Stack) malloc(sizeof(stack));
    stack->array = (STACK_ELEMENT_TYPE *) malloc(sizeof(STACK_ELEMENT_TYPE) * capacity);
    stack->top_idx = -1;
    stack->capacity = capacity;
    return stack;
}

/**
 * @brief Push a new node at top of the stack
 * @param stack Pointer of the stack
 * @param value Value of new value
 */
void PushStack(Stack stack, STACK_ELEMENT_TYPE value) {
    if (stack->top_idx == stack->capacity - 1) {
        fprintf(stderr, "Stack is full, cannot push new value\n");
        exit(PUSH_FULL_STACK_FAIL);
    }
    stack->array[stack->top_idx++] = value;
}

/**
 * @brief Pop the top value of the stack
 * @param stack Pointer of the stack
 * @return Value of the top element in the stack
 */
STACK_ELEMENT_TYPE PopStack(Stack stack) {
    if (stack->top_idx == -1) {
        fprintf(stderr, "Stack is empty, cannot pop value\n");
        exit(POP_EMPTY_STACK_FAIL);
    }
    return stack->array[stack->top_idx--];
}

/**
 * @brief Get size of the stack
 * @param stack Pointer of the stack
 * @return Size of the stack
 */
size_t GetStackSize(Stack stack) {
    return stack->top_idx + 1;
}

/**
 * @brief Print the stack
 * @param stack Pointer of the stack
 */
void PrintStack(Stack stack) {
    printf("Stack: ");
    for (int i = stack->top_idx; i != -1; i--) {
        printf("%d\n", stack->array[i]);
    }
}

/**
 * @brief Destruct the stack, and set the pointer to NULL after
 * @param stack Pointer of the pointer to stack
 */
void DestructStack(Stack *stack) {
    free((*stack)->array);
    free(*stack);
    *stack = NULL;
}