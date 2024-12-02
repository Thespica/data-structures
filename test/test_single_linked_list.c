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

#include <stdio.h>

#include "util.h"

#include "data-structures/list/single_linked_list.h"
#include "data-structures/util/generic.h"

int main(void) {
    SingleLinkedList list = NewSLL();
    for (int i = 0; i < 10; i++) {
        TailInsertSLL(list, NewInt(i));
    }
    printf("Size: %zu\n", GetSizeSLL(list));
    TraverseSLL(list, PrintIntNode);
    printf("\nSet value of the 5th node to 100:\n");
    SetInt(GetNodeAtSLL(list, 5)->value, 100);
    TraverseSLL(list, PrintIntNode);
    DeleteNodeAtSLL(list, 5);
    putchar('\n');
    printf("Size after delete one node: %zu\n", GetSizeSLL(list));
    TraverseSLL(list, PrintIntNode);
    DeleteSLL(list);
    return 0;
}
