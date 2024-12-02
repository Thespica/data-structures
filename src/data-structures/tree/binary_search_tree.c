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

#include "data-structures/tree/binary_search_tree.h"

#include "data-structures/memory/allocator.h"
#include "data-structures/tree/binary_tree.h"

extern struct allocator allocator_instance;

static void __ReplaceEqNodeByRightMin(TNode* eq_node_holder) {
    TNode* min_node_holder = &(*eq_node_holder)->right;
    while ((*min_node_holder)->left) {
        min_node_holder = &(*min_node_holder)->left;
    }
    (*min_node_holder)->left = (*eq_node_holder)->left;
    (*min_node_holder)->right = (*eq_node_holder)->right;
    DeleteTNode(*eq_node_holder);
    *eq_node_holder = *min_node_holder;
    *min_node_holder = NULL;
}

static void __ReplaceEqNodeByRight(TNode* eq_node_holder) {
    TNode node_to_delete = *eq_node_holder;
    *eq_node_holder = (*eq_node_holder)->right;
    DeleteTNode(node_to_delete);
}

static void __ReplaceEqNodeByLeft(TNode* eq_node_holder) {
    TNode node_to_delete = *eq_node_holder;
    *eq_node_holder = (*eq_node_holder)->left;
    DeleteTNode(node_to_delete);
}

static void __DeleteEqNodeAsLeaf(TNode* eq_node_holder) {
    DeleteTNode(*eq_node_holder);
    *eq_node_holder = NULL;
}

BinarySearchTree NewBST(NodeValue value, bool (*compare)(NodeValue small, NodeValue big),
                        bool (*eq)(NodeValue, NodeValue)) {
    BinarySearchTree new_bst =
        (BinarySearchTree)allocator_instance.allocate(sizeof(struct binary_search_tree));
    new_bst->tree = NewBinaryTree(value);
    new_bst->compare = compare;
    new_bst->eq = eq;
    return new_bst;
}

TNode* GetEqualNodeHolderInBST(BinarySearchTree tree, NodeValue value) {
    TNode* iter_node_holder = &tree->tree;
    while (!tree->eq((*iter_node_holder)->value, value)) {
        iter_node_holder = tree->compare((*iter_node_holder)->value, value)
                               ? &(*iter_node_holder)->right
                               : &(*iter_node_holder)->left;
        if (!*iter_node_holder) {
            return NULL;
        }
    }
    return iter_node_holder;
}

NodeValue GetMinValueInBST(BinarySearchTree tree) {
    TNode iter_node = tree->tree;
    while (iter_node->left) {
        iter_node = iter_node->left;
    }
    return iter_node->value;
}

NodeValue GetMaxValueInBST(BinarySearchTree tree) {
    TNode iter_node = tree->tree;
    while (iter_node->right) {
        iter_node = iter_node->right;
    }
    return iter_node->value;
}

void InsertValueInBST(BinarySearchTree tree, NodeValue value) {
    TNode* iter_node_holder = &tree->tree;
    while (*iter_node_holder) {
        if (tree->eq((*iter_node_holder)->value, value)) {
            return;
        }
        iter_node_holder = tree->compare((*iter_node_holder)->value, value)
                               ? &(*iter_node_holder)->right
                               : &(*iter_node_holder)->left;
    }
    *iter_node_holder = NewTNode(value, NULL, NULL);
}

void DeleteNodeInBST(BinarySearchTree tree, NodeValue value) {
    TNode* equal_node_holder = GetEqualNodeHolderInBST(tree, value);
    if (!*equal_node_holder) {
        return;
    }
    /*
     * left   right   situation
     * NULL + NULL -> 0
     * NULL + ptr  -> 1
     * ptr  + NULL -> 2
     * ptr  + ptr  -> 3
     */
    switch ((!!(*equal_node_holder)->left << 1) + !!(*equal_node_holder)->right) {
        case 0:
            __DeleteEqNodeAsLeaf(equal_node_holder);
            return;
        case 1:
            __ReplaceEqNodeByRight(equal_node_holder);
            return;
        case 2:
            __ReplaceEqNodeByLeft(equal_node_holder);
            return;
        case 3:
            __ReplaceEqNodeByRightMin(equal_node_holder);
    }
}

void DeleteBST(BinarySearchTree tree) {
    DeleteBinaryTree(tree->tree);
    allocator_instance.deallocate(tree);
}