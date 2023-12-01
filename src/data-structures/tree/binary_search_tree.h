#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "data-structures/base/nodes.h"
#include "data-structures/tree/binary_tree.h"

struct binary_search_tree {
    BinaryTree tree;
    bool (*compare)(NodeValue small, NodeValue big);
    bool (*eq)(NodeValue, NodeValue);
};

typedef struct binary_search_tree *BinarySearchTree;

BinarySearchTree NewBST(NodeValue value, bool (*compare)(NodeValue small, NodeValue big),
                        bool (*eq)(NodeValue, NodeValue));

TNode FindTNodeInBST(BinarySearchTree tree, NodeValue value);

NodeValue FindMinValueInBST(BinarySearchTree tree);

NodeValue FindMaxValueInBST(BinarySearchTree tree);

void InsertValueInBST(BinarySearchTree tree, NodeValue value);

void DeleteNodeInBST(BinarySearchTree tree, NodeValue value);

void DeleteBST(BinarySearchTree tree);

#endif  // BINARY_SEARCH_TREE_H
