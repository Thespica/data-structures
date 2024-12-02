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

#include "data-structures/tree/binary_tree.h"

#include "data-structures/memory/allocator.h"
#include "data-structures/queue/queue.h"
#include "data-structures/stack/stack.h"
#include "data-structures/util/generic.h"

extern struct allocator allocator_instance;

BinaryTree NewBinaryTree(NodeValue value) { return NewTNode(value, NULL, NULL); }

BinaryTree NewBinaryTreeFromPreOrderList(SingleLinkedList pre_order_list) {
    if (GetSizeSLL(pre_order_list) == 0) {
        return NULL;
    }
    TNode root = NewTNode(PopHeadSLL(pre_order_list), NULL, NULL);
    Stack recording_right_node_stack = NewStack();
    PushStack(recording_right_node_stack, &root->right);
    TNode* current_node = &root->left;
    NodeValue node_value;
    while (GetSizeSLL(pre_order_list)) {
        node_value = PopHeadSLL(pre_order_list);
        if (node_value) {
            *current_node = NewTNode(node_value, NULL, NULL);
            PushStack(recording_right_node_stack, &(*current_node)->right);
            current_node = &(*current_node)->left;
        } else {
            if (!GetStackSize(recording_right_node_stack)) {
                break;
            }
            current_node = PopStack(recording_right_node_stack);
        }
    }
    DeleteSLL(pre_order_list);
    return root;
}

void PreOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    /*
     * Fuck recursive implementation
     *
        if (!tree) {
            return;
        }
        for_traversing_node(tree);
        PreOrderTraversal(tree->left, for_traversing_node);
        PreOrderTraversal(tree->right, for_traversing_node);
    */
    Stack stack = NewStack();
    TNode current_node = tree;
    while (true) {
        for_traversing_node(current_node);
        if (current_node == NULL) {
            if (!GetStackSize(stack)) {
                break;
            }
            current_node = PopStack(stack);
        } else {
            PushStack(stack, current_node->right);
            current_node = current_node->left;
        }
    }
    DeleteStack(stack);
}

void InOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    /*
        if (!tree) {
            return;
        }
        InOrderTraversal(tree->left, for_traversing_node);
        for_traversing_node(tree);
        InOrderTraversal(tree->right, for_traversing_node);
    */
    Stack stack = NewStack();
    TNode current_node = tree;
    while (true) {
        if (current_node == NULL) {
            for_traversing_node(current_node);
            if (!GetStackSize(stack)) {
                break;
            }
            current_node = PopStack(stack);
            for_traversing_node(current_node);
            current_node = current_node->right;
        } else {
            PushStack(stack, current_node);
            current_node = current_node->left;
        }
    }
    DeleteStack(stack);
}

void PostOrderTraversal(BinaryTree tree, void (*for_traversing_node)(TNode)) {
    /*
        if (!tree) {
            return;
        }
        PostOrderTraversal(tree->left, for_traversing_node);
        PostOrderTraversal(tree->right, for_traversing_node);
        for_traversing_node(tree);
    */
    Stack stack = NewStack();
    Stack is_searched_stack = NewStack();
    TNode current_node = tree;
    while (true) {
        if (current_node == NULL) {
            if (!GetStackSize(stack)) {
                break;
            }
            if (GetInt(TopStack(is_searched_stack))) {
                DeleteAndGetInt(PopStack(is_searched_stack));
                for_traversing_node(PopStack(stack));
            } else {  // switch to right subtree
                SetInt(TopStack(is_searched_stack), true);
                current_node = ((TNode)TopStack(stack))->right;
            }
        } else {
            PushStack(stack, current_node);
            PushStack(is_searched_stack, NewInt(false));
            current_node = current_node->left;
        }
    }
    DeleteStack(stack);
    DeleteStack(is_searched_stack);
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

void DeleteBinaryTree(BinaryTree tree) { PostOrderTraversal(tree, DeleteTNode); }