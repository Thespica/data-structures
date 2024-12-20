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

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "data-structures/base/nodes.h"
#include "data-structures/tree/binary_tree.h"

/**
 * The binary search tree interface
 * Contains the binary tree and the compare functions
 */
struct binary_search_tree {
    BinaryTree tree;
    bool (*compare)(NodeValue small, NodeValue big);
    bool (*eq)(NodeValue, NodeValue);
};

/**
 * The binary search tree holder, which points to the binary search tree in heap
 */
typedef struct binary_search_tree* BinarySearchTree;

/**
 * Create a new binary search tree
 *
 * @param value The value of the root node
 * @param compare The compare function
 * @param eq The equal function
 * @return The new binary search tree
 */
BinarySearchTree NewBST(NodeValue value, bool (*compare)(NodeValue small, NodeValue big),
                        bool (*eq)(NodeValue, NodeValue));

/**
 * Find the node in the binary search tree
 *
 * @param tree The binary search tree
 * @param value The value to find
 * @return The node with the value, or NULL if not found
 */
TNode* GetEqualNodeHolderInBST(BinarySearchTree tree, NodeValue value);

/**
 * Find the minimum value in the binary search tree
 *
 * @param tree The binary search tree
 * @return The minimum value in the binary search tree
 */
NodeValue GetMinValueInBST(BinarySearchTree tree);

/**
 * Find the maximum value in the binary search tree
 *
 * @param tree The binary search tree
 * @return The maximum value in the binary search tree
 */
NodeValue GetMaxValueInBST(BinarySearchTree tree);

/**
 *  Insert a value into the binary search tree
 *
 * @param tree The binary search tree
 * @param value The value to insert
 */
void InsertValueInBST(BinarySearchTree tree, NodeValue value);

/**
 *  Delete a node in the binary search tree
 *
 * @param tree The binary search tree
 * @param value The value to delete
 */
void DeleteNodeInBST(BinarySearchTree tree, NodeValue value);

/**
 * Delete the binary search tree
 *
 * @param tree The binary search tree
 */
void DeleteBST(BinarySearchTree tree);

#endif  // BINARY_SEARCH_TREE_H
