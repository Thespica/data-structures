#include <stdio.h>
#include <stdlib.h>

#define SINGLE_LINKED_LIST_ELEMENT_TYPE STACK_ELEMENT_TYPE
#include "data-structures/stack/stack.h"
#include "data-structures/list/single_linked_list.h"

Stack ConstructStack(void) {
    return ConstructSLL();
}

void PushStack(Stack stack, STACK_ELEMENT_TYPE value) {
    HeadInsertSLL(stack, value);
}

STACK_ELEMENT_TYPE PopStack(Stack stack) {
    if (GetNodesNumSLL(stack) == 0) {
        printf("Stack is empty!\n");
        exit(POP_EMPTY_STACK_FAIL);
    }
    STACK_ELEMENT_TYPE ret = GetNodeAtSLL(stack, 1)->value;
    DeleteNodeAtSLL(stack, 1);
    return ret;
}

size_t GetStackSize(Stack stack) {
    return GetNodesNumSLL(stack);
}

void PrintStack(Stack stack) {
    PrintSLL(stack);
}

void DestructStack(Stack *stack) {
    DestructSLL(stack);
}