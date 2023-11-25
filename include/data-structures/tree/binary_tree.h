#ifndef DATA_STRUCT_BINARY_TREE_H
#define DATA_STRUCT_BINARY_TREE_H

#ifndef BINARY_TREE_ELEMENT_TYPE
#define BINARY_TREE_ELEMENT_TYPE int
#endif

/**
 * The node of binary tree
 */
struct binary_tree_node {
    BINARY_TREE_ELEMENT_TYPE value;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
};

/**
 * The binary tree as pointer
 */
typedef struct binary_tree_node *BinaryTree;

/**
 * Construct a binary tree
 *
 * @return Pointer of the binary tree
 */
BinaryTree ConstructBinaryTree(void);

/**
 * Pre order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void PreOrderTraversal(BinaryTree tree, void (*for_traversing_node)(const struct binary_tree_node *));

/**
 * In order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void InOrderTraversal(BinaryTree tree, void (*for_traversing_node)(const struct binary_tree_node *));

/**
 * Post order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void PostOrderTraversal(BinaryTree tree, void (*for_traversing_node)(struct binary_tree_node *));

/**
 * Level order traversal the binary tree
 *
 * @param tree Pointer of the binary tree
 * @param for_traversing_node Function pointer to process each node when traversing
 */
void LevelOrderTraversal(BinaryTree tree, void (*for_traversing_node)(const struct binary_tree_node *));

/**
 * Destruct the binary tree
 *
 * @param tree Pointer of the binary tree
 */
void DestructBinaryTree(BinaryTree *tree);


#endif //DATA_STRUCT_BINARY_TREE_H
