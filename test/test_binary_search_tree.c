#include "util.h"

#include "data-structures/tree/binary_search_tree.h"
#include "data-structures/util/generic.h"

int main(void) {
    void (*print_func)(TNode) = PrintIntTNode;
    int tree_element_value[7] = {4, 2, 1, 3, 6, 5, 8};
    BinarySearchTree bst = NewBST(NewInt(tree_element_value[0]), IntCmp, IntEq);
    for (int i = 1; i < 7; i++) {
        InsertValueInBST(bst, NewInt(tree_element_value[i]));
    }
    InOrderTraversal(bst->tree, print_func);
    putchar('\n');
    InsertValueInBST(bst, NewInt(7));
    InOrderTraversal(bst->tree, print_func);
    putchar('\n');
    void* int_to_delete = NewInt(5);
    bool exist = FindTNodeInBST(bst, int_to_delete)->value;
    printf("find 5: %s\n", exist ? "yes" : "no");
    DeleteNodeInBST(bst, int_to_delete);
    exist = !!FindTNodeInBST(bst, int_to_delete);
    printf("find 5: %s\n", exist ? "yes" : "no");
    InOrderTraversal(bst->tree, print_func);
    putchar('\n');
    DeleteAndGetInt(int_to_delete);
    DeleteBST(bst);
}