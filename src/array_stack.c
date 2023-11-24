#include <stdio.h>
#include <stdlib.h>

#include "data-structures/stack/array_stack.h"

ArrayStack ConstructStack(size_t capacity) {
ArrayStack stack = (ArrayStack) malloc(sizeof(struct array_stack));
    stack->array = (STACK_ELEMENT_TYPE *) malloc(sizeof(STACK_ELEMENT_TYPE) * capacity);
    stack->top_idx = -1;
    stack->capacity = capacity;
    return stack;
}

/**
 * @brief Push a new node at top of the array_stack
 * @param stack Pointer of the array_stack
 * @param value Value of new value
 */
void PushStack(ArrayStack stack, STACK_ELEMENT_TYPE value) {
    if (stack->top_idx == stack->capacity - 1) {
        fprintf(stderr, "Stack is full, cannot push new value\n");
        exit(PUSH_FULL_STACK_FAIL);
    }
    stack->array[stack->top_idx++] = value;
}

/**
 * @brief Pop the top value of the array_stack
 * @param stack Pointer of the array_stack
 * @return Value of the top element in the array_stack
 */
STACK_ELEMENT_TYPE PopStack(ArrayStack stack) {
    if (stack->top_idx == -1) {
        fprintf(stderr, "Stack is empty, cannot pop value\n");
        exit(POP_EMPTY_STACK_FAIL);
    }
    return stack->array[stack->top_idx--];
}

/**
 * @brief Get size of the array_stack
 * @param stack Pointer of the array_stack
 * @return Size of the array_stack
 */
size_t GetStackSize(ArrayStack stack) {
    return stack->top_idx + 1;
}

/**
 * @brief Print the array_stack
 * @param stack Pointer of the array_stack
 */
void PrintStack(ArrayStack stack) {
    printf("Stack: ");
    for (int i = stack->top_idx; i != -1; i--) {
        printf("%d\n", stack->array[i]);
    }
}

/**
 * @brief Destruct the array_stack, and set the pointer to NULL after
 * @param stack Pointer of the pointer to array_stack
 */
void DestructStack(ArrayStack *stack) {
    free((*stack)->array);
    free(*stack);
    *stack = NULL;
}