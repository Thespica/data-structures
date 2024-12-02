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