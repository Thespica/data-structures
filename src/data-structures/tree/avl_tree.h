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

#ifndef DATA_STRUCTURES_AVL_TREE_H
#define DATA_STRUCTURES_AVL_TREE_H

#include "data-structures/base/nodes.h"

struct tree_avl {
    TNodeWithDepth root;
        bool (*compare)(NodeValue small, NodeValue big);
        bool (*eq)(NodeValue, NodeValue);
};

typedef struct tree_avl* TreeAVL;

TreeAVL NewAVLTree(NodeValue value, bool (*compare)(NodeValue small, NodeValue big),
                   bool (*eq)(NodeValue smaller, NodeValue bigger));

void InsertValueIntoTreeAVL(TreeAVL tree, NodeValue value);

TNodeWithDepth* GetEqualNodeHolderInTreeAVL(TreeAVL tree, NodeValue value);

void TraverseTreeAVL(TNodeWithDepth root, void (*for_traversing_node)(TNodeWithDepth));

void DeleteTreeAVL(TreeAVL tree);

#endif  // DATA_STRUCTURES_AVL_TREE_H
