#include "data-structures/tree/avl_tree.h"

#include <stddef.h>

#include "data-structures/memory/allocator.h"
#include "data-structures/stack/stack.h"
#include "data-structures/util/error_code.h"

extern struct allocator allocator_instance;

static inline int __GetBalanceFactor(TNodeWithDepth* node) {
    if (*node == NULL) {
        return 0;
    }
    int ret = ((*node)->left == NULL ? 0 : (*node)->left->depth) -
              ((*node)->right == NULL ? 0 : (*node)->right->depth);
    return ret;
}

static inline int __MaxDepth(TNodeWithDepth left, TNodeWithDepth right) {
    if (left == NULL && right == NULL) {
        return 0;
    }
    if (left == NULL) {
        return right->depth;
    }
    if (right == NULL) {
        return left->depth;
    }
    return left->depth > right->depth ? left->depth : right->depth;
}

static inline void __RightRotate(TNodeWithDepth* father_node_holder) {
    TNodeWithDepth left_node = (*father_node_holder)->left;
    (*father_node_holder)->left = left_node->right;
    left_node->right = *father_node_holder;
    (*father_node_holder)->depth =
        __MaxDepth((*father_node_holder)->left, (*father_node_holder)->right) + 1;
    left_node->depth = __MaxDepth(left_node->left, left_node->right) + 1;
    *father_node_holder = left_node;
}

static inline void __LeftRotate(TNodeWithDepth* father_node) {
    TNodeWithDepth right_node = (*father_node)->right;
    (*father_node)->right = right_node->left;
    right_node->left = *father_node;
    (*father_node)->depth = __MaxDepth((*father_node)->left, (*father_node)->right) + 1;
    right_node->depth = __MaxDepth(right_node->left, right_node->right) + 1;
    *father_node = right_node;
}

TreeAVL NewAVLTree(NodeValue value, bool (*compare)(NodeValue small, NodeValue big),
                   bool (*eq)(NodeValue, NodeValue)) {
    TNodeWithDepth root = NewTNodeWithDepth(value, NULL, NULL);
    TreeAVL tree = (TreeAVL)allocator_instance.allocate(sizeof(struct tree_avl));
    tree->root = root;
    tree->compare = compare;
    tree->eq = eq;
    return tree;
}

typedef struct {
    TNodeWithDepth* node_holder;
    int balance_factor;
    bool child_is_right;
} recorder;

static recorder* NewRecorder(TNodeWithDepth* node_holder, int balance_factor, bool child_is_right) {
    recorder* ret = (recorder*)allocator_instance.allocate(sizeof(recorder));
    ret->node_holder = node_holder;
    ret->balance_factor = balance_factor;
    ret->child_is_right = child_is_right;
    return ret;
}

static void DeleteRecorder(recorder* recorder) { allocator_instance.deallocate(recorder); }

void InsertValueIntoTreeAVL(TreeAVL tree, NodeValue value) {
    /*
                |
                a
               / \
              b   c
             /\   /\
            d  e  f g
           /\ /\ /\ /\
    */

    Stack stack = NewStack();
    TNodeWithDepth* node_holder = &(tree->root);
    bool child_is_right;
    while (*node_holder != NULL) {
        if (tree->eq(value, (*node_holder)->value)) {
            DeleteStack(stack);
        }
        child_is_right = tree->compare((*node_holder)->value, value);
        PushStack(stack, NewRecorder(node_holder, __GetBalanceFactor(node_holder), child_is_right));
        recorder* temp = TopStack(stack);
        node_holder = child_is_right ? &(*node_holder)->right : &(*node_holder)->left;
    }
    *node_holder = NewTNodeWithDepth(value, NULL, NULL);

    bool grand_child_is_right = false;
    recorder* current_recorder;
    int origin_balance_factor;
    enum crash_status { LL, LR, RL, RR } crash_status;
    while (GetStackSize(stack) != 0) {
        current_recorder = PopStack(stack);
        node_holder = current_recorder->node_holder;
        origin_balance_factor = current_recorder->balance_factor;
        child_is_right = current_recorder->child_is_right;
        DeleteRecorder(current_recorder);
        if ((origin_balance_factor == -1 && !child_is_right) ||
            (origin_balance_factor == 1 && child_is_right)) {
            DeleteStack(stack);
            return;
        }
        if (origin_balance_factor == 0) {
            grand_child_is_right = child_is_right;
            (*node_holder)->depth++;
            continue;
        }
        /*
         * child     grand_child    situation
         *   left    +   left      ->  LL
         *   left    +   right     ->  LR
         *   right   +   left      ->  RL
         *   right   +   right     ->  RR
         */
        crash_status = (child_is_right << 1) + grand_child_is_right;
        switch (crash_status) {
            case LL: {
                __RightRotate(node_holder);
                DeleteStack(stack);
                return;
            }
            case LR: {
                __LeftRotate(&(*node_holder)->left);
                __RightRotate(node_holder);
                DeleteStack(stack);
                return;
            }
            case RL: {
                __RightRotate(&(*node_holder)->right);
                __LeftRotate(node_holder);
                DeleteStack(stack);
                return;
            }
            case RR: {
                __LeftRotate(node_holder);
                DeleteStack(stack);
                return;
            }
            default: {
                fprintf(stderr, "Unknown crash status: %d\n", crash_status);
                exit(ASSERT_IMPOSSIBLE);
            }
        }
    }
}

TNodeWithDepth* GetEqualNodeHolderInTreeAVL(TreeAVL tree, NodeValue value) {
    if (tree == NULL || tree->root == NULL) {
        return NULL;
    }
    TNodeWithDepth* node_holder = &(tree->root);
    while (*node_holder != NULL) {
        if (tree->eq((*node_holder)->value, value)) {
            return node_holder;
        }
        node_holder = tree->compare((*node_holder)->value, value) ? &((*node_holder)->right)
                                                                  : &((*node_holder)->left);
    }
    return NULL;
}

void TraverseTreeAVL(TNodeWithDepth root, void (*for_traversing_node)(TNodeWithDepth)) {
    if (root == NULL) {
        return;
    }
    TraverseTreeAVL(root->left, for_traversing_node);
    for_traversing_node(root);
    TraverseTreeAVL(root->right, for_traversing_node);
}

static void DeleteTreeAVLNode(TNodeWithDepth node_holder) {
    if (node_holder == NULL) {
        return;
    }
    DeleteTreeAVLNode(node_holder->left);
    DeleteTreeAVLNode(node_holder->right);
    DeleteTNodeWithDepth(node_holder);
}

void DeleteTreeAVL(TreeAVL tree) {
    if (tree == NULL) {
        return;
    }
    DeleteTreeAVLNode(tree->root);
    allocator_instance.deallocate(tree);
}