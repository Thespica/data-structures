#include "data-structures/tree/binary_tree.h"

#include "data-structures/queue/queue.h"
#include "data-structures/memory/allocator.h"

extern struct allocator allocator_instance;

BinaryTree ConstructBinaryTree(NodeValue value) {
    return NewTNode(value, NULL, NULL);
}

void PreOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    if (!tree) {
        return;
    }
    for_traversing_node(tree);
    PreOrderTraversal(tree->left, for_traversing_node);
    PreOrderTraversal(tree->right, for_traversing_node);
}

void InOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    if (!tree) {
        return;
    }
    InOrderTraversal(tree->left, for_traversing_node);
    for_traversing_node(tree);
    InOrderTraversal(tree->right, for_traversing_node);
}

void PostOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    if (!tree) {
        return;
    }
    PostOrderTraversal(tree->left, for_traversing_node);
    PostOrderTraversal(tree->right, for_traversing_node);
    for_traversing_node(tree);
}

void LevelOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    Queue queen = NewQueue();
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
    DeleteQueue(queen);
}

void DestructBinaryTree(BinaryTree tree) {
    PostOrderTraversal(tree, DeleteTNode);
}