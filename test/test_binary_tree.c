#include "util.h"

#include "data-structures/tree/binary_tree.h"
#include "data-structures/util/generic.h"

int main(void) {
    int pre_order_array[] = {4, 2, 1, 0, 0, 3, 0, 0, 6, 5, 0, 0, 8, 0, 0};
    SingleLinkedList pre_order_list = NewSLL();
    for (int i = 0; i < sizeof pre_order_array / sizeof(int); i++) {
        TailInsertSLL(pre_order_list, pre_order_array[i] ? NewInt(pre_order_array[i]) : NULL);
    }
    BinaryTree tree = NewBinaryTreeFromPreOrderList(pre_order_list);
    PreOrderTraversal(tree, PrintIntTNode);
    putchar('\n');
    InOrderTraversal(tree, PrintIntTNode);
    putchar('\n');
    PostOrderTraversal(tree, PrintIntTNode);
    DeleteBinaryTree(tree);
}