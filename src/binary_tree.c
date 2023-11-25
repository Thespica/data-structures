#include <stdlib.h>

#include "data-structures/tree/binary_tree.h"
#define QUEUE_ELEMENT_TYPE (struct binary_tree_node*)
#include "data-structures/queue/queue.h"

BinaryTree ConstructBinaryTree(void) {
    BinaryTree tree = (BinaryTree) malloc(sizeof(struct binary_tree_node));
    tree->value = 0;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void PreOrderTraversal(BinaryTree tree, void (*for_traversing_node)(const struct binary_tree_node *)) {
    if (!tree) {
        return;
    }
    for_traversing_node(tree);
    PreOrderTraversal(tree->left, for_traversing_node);
    PreOrderTraversal(tree->right, for_traversing_node);
}

void InOrderTraversal(BinaryTree tree, void (*for_traversing_node)(const struct binary_tree_node *)) {
    if (!tree) {
        return;
    }
    InOrderTraversal(tree->left, for_traversing_node);
    for_traversing_node(tree);
    InOrderTraversal(tree->right, for_traversing_node);
}

void PostOrderTraversal(BinaryTree tree, void (*for_traversing_node)(struct binary_tree_node *)) {
    if (!tree) {
        return;
    }
    PostOrderTraversal(tree->left, for_traversing_node);
    PostOrderTraversal(tree->right, for_traversing_node);
    for_traversing_node(tree);
}

void LevelOrderTraversal(BinaryTree tree, void (*for_traversing_node)(const struct binary_tree_node *)) {
    Queue queen = ConstructQueue();
    EnQueue(queen, tree);
    while (GetQueueSize(queen)) {
        BinaryTree node = DeQueue(queen);
        for_traversing_node(node);
        if (node->left) {
            EnQueue(queen, node->left);
        }
        if (node->right) {
            EnQueue(queen, node->right);
        }
    }
    DestructQueue(&queen);
}

static void free_tree_node(struct binary_tree_node *node) {
    free(node);
}

void DestructBinaryTree(BinaryTree *tree) {
    PostOrderTraversal(*tree, free_tree_node);
    *tree = NULL;
}