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

#ifndef DATA_STRUCT_UTIL_H
#define DATA_STRUCT_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "data-structures/base/nodes.h"
#include "data-structures/memory/allocator.h"
#include "data-structures/util/generic.h"

struct allocator allocator_instance = {
    .allocate = malloc, .reallocate = realloc, .deallocate = free};

void PrintIntNode(Node node) {
    if (node == NULL) {
        //        printf("NULL ");
        return;
    }
    printf("%d ", GetInt(node->value));
}

void PrintIntTNode(TNode t_node) {
    if (t_node == NULL) {
        //        printf("NULL ");
        return;
    }
    printf("%d ", GetInt(t_node->value));
}

void PrintIntTNodeWithDepth(TNodeWithDepth t_node) {
    if (t_node == NULL) {
        //        printf("NULL ");
        return;
    }
    printf("%d ", GetInt(t_node->value));
}

#endif  // DATA_STRUCT_UTIL_H
