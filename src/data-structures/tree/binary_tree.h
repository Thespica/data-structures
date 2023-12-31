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
