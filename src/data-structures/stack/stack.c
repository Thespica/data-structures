#include "data-structures/stack/stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/list/single_linked_list.h"
#include "data-structures/memory/allocator.h"
#include "data-structures/util/error_code.h"

extern struct allocator allocator_instance;

Stack NewStack(void) {
    return NewSLL();
}

void PushStack(Stack stack, NodeValue value) {
    HeadInsertSLL(stack, value);
}

NodeValue PopStack(Stack stack) {
    if (GetStackSize(stack) == 0) {
        fprintf(stderr, "Stack is empty!\n");
        exit(POP_EMPTY_STACK_FAIL);
    }
    return MoveNodeValueAtSLL(stack, 0);
}

size_t GetStackSize(Stack stack) {
    return GetSizeSLL(stack);
}

void TraverseStack(Stack stack, void (*for_traversing_node)(Node)) {
    TraverseSLL(stack->next, for_traversing_node);
}

void DeleteStack(Stack stack) {
    DeleteSLL(stack);
}