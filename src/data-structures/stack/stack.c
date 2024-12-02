/*
 * Copyright 2024 Thespica
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "data-structures/stack/stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/list/single_linked_list.h"
#include "data-structures/memory/allocator.h"
#include "data-structures/util/error_code.h"

extern struct allocator allocator_instance;

Stack NewStack(void) { return NewSLL(); }

NodeValue TopStack(Stack stack) { return GetStackSize(stack) ? stack->next->value : NULL; }

void PushStack(Stack stack, NodeValue value) { HeadInsertSLL(stack, value); }

NodeValue PopStack(Stack stack) {
    if (GetStackSize(stack) == 0) {
        fprintf(stderr, "Stack is empty!\n");
        exit(POP_EMPTY_STACK_FAIL);
    }
    return MoveNodeValueAtSLL(stack, 0);
}

size_t GetStackSize(Stack stack) { return GetSizeSLL(stack); }

void TraverseStack(Stack stack, void (*for_traversing_node)(Node)) {
    TraverseSLL(stack->next, for_traversing_node);
}

void DeleteStack(Stack stack) { DeleteSLL(stack); }