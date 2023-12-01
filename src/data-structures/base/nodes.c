#include "data-structures/base/nodes.h"

#include "data-structures/memory/allocator.h"

extern struct allocator allocator_instance;

Node NewNode(NodeValue value, Node next) {
    Node new_node = (Node)allocator_instance.allocate(sizeof(struct node));
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

NodeValue ReplaceNodeValue(Node node, NodeValue value) {
    NodeValue ret_value = node->value;
    node->value = value;
    return ret_value;
}

NodeValue MoveNodeValue(Node node) {
    NodeValue ret_value = node->value;
    allocator_instance.deallocate(node);
    return ret_value;
}

void DeleteNode(Node node) {
    allocator_instance.deallocate(node->value);
    allocator_instance.deallocate(node);
}

TNode NewTNode(NodeValue value, TNode left, TNode right) {
    TNode new_t_node =
        (TNode)allocator_instance.allocate(sizeof(struct t_node));
    new_t_node->value = value;
    new_t_node->left = left;
    new_t_node->right = right;
    return new_t_node;
}

NodeValue ReplaceTNodeValue(TNode t_node, NodeValue value) {
    NodeValue ret_value = t_node->value;
    t_node->value = value;
    return ret_value;
}

NodeValue MoveTNodeValue(TNode t_node) {
    NodeValue ret_value = t_node->value;
    allocator_instance.deallocate(t_node);
    return ret_value;
}

void DeleteTNode(TNode t_node) {
    allocator_instance.deallocate(t_node->value);
    allocator_instance.deallocate(t_node);
}