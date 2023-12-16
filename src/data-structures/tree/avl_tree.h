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
