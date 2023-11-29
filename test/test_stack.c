#include "util.h"

#include "data-structures/stack/stack.h"

int main(void) {
    Stack stack = NewStack();
    for (int i = 0; i < 10; i++) {
        PushStack(stack, NewInt(i));
    }
    printf("Size: %zu\n", GetStackSize(stack));
    TraverseStack(stack, PrintIntNode);
    printf("\nPop node: %d\n", DeleteAndGetInt(PopStack(stack)));
    printf("Size after pop one node: %zu\n", GetStackSize(stack));
    TraverseStack(stack, PrintIntNode);
    DeleteStack(stack);
    return 0;
}