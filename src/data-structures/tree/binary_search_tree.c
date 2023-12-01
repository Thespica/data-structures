#include "data-structures/tree/binary_search_tree.h"

#include "data-structures/memory/allocator.h"
#include "data-structures/tree/binary_tree.h"
#include "data-structures/util/error_code.h"

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

TNode FindTNodeInBST(BinarySearchTree tree, NodeValue value) {
    TNode iter_node = tree->tree;
    while (iter_node) {
        if (tree->eq(iter_node->value, value)) {
            return iter_node;
        }
        iter_node = tree->compare(iter_node->value, value) ? iter_node->right : iter_node->left;
    }
    return NULL;
}

NodeValue FindMinValueInBST(BinarySearchTree tree) {
    TNode iter_node = tree->tree;
    while (iter_node->left) {
        iter_node = iter_node->left;
    }
    return iter_node->value;
}

NodeValue FindMaxValueInBST(BinarySearchTree tree) {
    TNode iter_node = tree->tree;
    while (iter_node->right) {
        iter_node = iter_node->right;
    }
    return iter_node->value;
}

void InsertValueInBST(BinarySearchTree tree, NodeValue value) {
    TNode* ptr_to_change = &tree->tree;
    for (TNode iter_node = tree->tree; iter_node; iter_node = *ptr_to_change) {
        if (tree->eq(iter_node->value, value)) {
            return;
        }
        ptr_to_change =
            tree->compare(iter_node->value, value) ? &iter_node->right : &iter_node->left;
    }
    *ptr_to_change = NewTNode(value, NULL, NULL);
}

void DeleteNodeInBST(BinarySearchTree tree, NodeValue value) {
    TNode* equal_node_holder = &tree->tree;
    while (!tree->eq((*equal_node_holder)->value, value)) {
        equal_node_holder = tree->compare((*equal_node_holder)->value, value)
                                ? &(*equal_node_holder)->right
                                : &(*equal_node_holder)->left;
    }
    /*
     * left   right   situation
     * ptr  + ptr  -> 0
     * NULL + ptr  -> 1
     * ptr  + NULL -> 2
     * NULL + NULL -> 3
     */
    switch ((!(*equal_node_holder)->left << 1) + !(*equal_node_holder)->right) {
        case 0:
            __ReplaceEqNodeByRightMin(equal_node_holder);
            return;
        case 1:
            __ReplaceEqNodeByRight(equal_node_holder);
            return;
        case 2:
            __ReplaceEqNodeByLeft(equal_node_holder);
            return;
        case 3:
            __DeleteEqNodeAsLeaf(equal_node_holder);
            return;
        default:
            fprintf(stderr, "Error: unexpected situation in DeleteNodeInBST\n");
            exit(666);
    }
}

void DeleteBST(BinarySearchTree tree) {
    DeleteBinaryTree(tree->tree);
    allocator_instance.deallocate(tree);
}