#ifndef DATA_STRUCT_NODES_H
#define DATA_STRUCT_NODES_H

/**
 * The value of a node, which is a void pointer for runtime generic.
 */
typedef void *NodeValue;

/**
 * The node with one value and one pointer to next node.
 * The value is a void pointer for runtime generic.
 * The next pointer is a pointer to next node.
 */
struct node {
    NodeValue value;
    struct node *next;
};

/**
 * The node as a whole, which is a pointer to the actual node.
 */
typedef struct node *Node;

/**
 * Construct a node in heap
 *
 * @param value Pointer to the value in heap
 * @param next Pointer to the next node
 * @return
 */
struct node *NewNode(NodeValue value, struct node *next);

/**
 * Get the value of a node, the original value will be freed
 * @param node Pointer of the node
 * @param value Pointer of the new value
 */
void SetNodeValue(Node node, NodeValue value);

/**
 * Delete a node in heap, set the node holder to NULL after
 *
 * @param node Pointer of the node holder
 */
void DeleteNode(Node *node);


#endif //DATA_STRUCT_NODES_H
