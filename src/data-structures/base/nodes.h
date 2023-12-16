#ifndef DATA_STRUCT_NODES_H
#define DATA_STRUCT_NODES_H

#include <stdbool.h>
#include <stddef.h>

/**
 * The value of a node, which is a void pointer holding the actual value for
 * runtime generic.
 */
typedef void* NodeValue;

/**
 * The node with one value and one pointer to next node.
 * The value is a void pointer holding the actual value for runtime generic.
 * The next pointer is a pointer to next node.
 */
struct node {
    NodeValue value;
    struct node* next;
};

/**
 * The node as a whole, which is a pointer to the actual node.
 */
typedef struct node* Node;

/**
 * Construct a node in heap
 *
 * @param value Pointer to the value in heap
 * @param next Pointer to the next node
 * @return Pointer of the node
 */
Node NewNode(NodeValue value, Node next);

/**
 * Replace the value of a node, the original value must be hold or free
 *
 * @param node Pointer of the node
 * @param value Pointer of the actual value in heap
 * @return Pointer of the original value, which must be hold or free
 */
NodeValue ReplaceNodeValue(Node node, NodeValue value);

/**
 * Move the value of a node, the node itself will be free, suggest to set the
 * original node holder to NULL after. The value must be hold or free after.
 *
 * @param node The node in heap
 * @return Pointer of the actual value in heap, which must be hold or free
 */
NodeValue MoveNodeValue(Node node);

/**
 * Delete the node in heap, , suggest to set the original t_node holder to NULL
 * after
 *
 * @param node Pointer of the node holder
 */
void DeleteNode(Node node);

/**
 * The node with Two pointers to left and right node.
 * Can be seen as binary Tree node, or node with Two pointer to node.
 */
struct t_node {
    NodeValue value;
    struct t_node* left;
    struct t_node* right;
};

/**
 * The t_node as a whole, which is a pointer to the actual t_node.
 */
typedef struct t_node* TNode;

/**
 * Construct a t_node in heap
 *
 * @param value Pointer to the value in heap
 * @param left Pointer to the left node
 * @param right Pointer to the right node
 * @return Pointer of the t_node
 */
TNode NewTNode(NodeValue value, TNode left, TNode right);

/**
 * Replace the value of a t_node, the original value must be hold or free
 *
 * @param t_node Pointer of the t_node
 * @param value Pointer of the actual value in heap
 * @return Pointer of the original value, which must be hold or free
 */
NodeValue ReplaceTNodeValue(TNode t_node, NodeValue value);

/**
 * Move the value of a t_node, the t_node itself will be free, suggest to set
 * the original t_node holder to NULL after. The value must be hold or free
 * after.
 *
 * @param t_node The t_node in heap
 * @return Pointer of the actual value in heap, which must be hold or free
 */
NodeValue MoveTNodeValue(TNode t_node);

/**
 * Delete the t_node in heap, suggest to set the original t_node holder to NULL
 * after
 *
 * @param t_node Pointer of the t_node
 */
void DeleteTNode(TNode t_node);

struct t_node_with_depth {
    NodeValue value;
    int depth;
    struct t_node_with_depth* left;
    struct t_node_with_depth* right;
};

typedef struct t_node_with_depth* TNodeWithDepth;

TNodeWithDepth NewTNodeWithDepth(NodeValue value, TNodeWithDepth left, TNodeWithDepth right);

void DeleteTNodeWithDepth(TNodeWithDepth t_node_with_depth);

#endif  // DATA_STRUCT_NODES_H
