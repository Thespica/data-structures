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

#ifndef DATA_STRUCT_BINARY_TREE_H
#define DATA_STRUCT_BINARY_TREE_H

#include "data-structures/base/nodes.h"
#include "data-structures/list/single_linked_list.h"

/**
 * The binary tree as pointer
 */
typedef TNode BinaryTree;

/**
 * Construct a binary tree
 *
 * @param value Value of root node
 * @return Pointer of the binary tree
 */
BinaryTree NewBinaryTree(NodeValue value);

BinaryTree NewBinaryTreeFromPreOrderList(SingleLinkedList pre_order_list);

/**
 * Pre order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void PreOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode));

/**
 * In order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void InOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode));

/**
 * Post order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void PostOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode));

/**
 * Level order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void LevelOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode));

/**
 * Destruct the binary tree
 *
 * @param tree Pointer of the binary tree
 */
void DeleteBinaryTree(BinaryTree tree);

#endif  // DATA_STRUCT_BINARY_TREE_H
