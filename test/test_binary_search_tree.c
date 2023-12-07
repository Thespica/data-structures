#include "util.h"

#include "data-structures/tree/binary_search_tree.h"
#include "data-structures/util/generic.h"

int main(void) {
    int tree_element_value[] = {4, 2, 1, 3, 6, 5, 8};
    // construct a binary search tree
    BinarySearchTree bst = NewBST(NewInt(tree_element_value[0]), IntCmp, IntEq);
    for (int i = 1; i < 7; i++) {
        InsertValueInBST(bst, NewInt(tree_element_value[i]));
    }
    // print, find min and max
    InOrderTraversal(bst->tree, PrintIntTNode);
    printf("\nMinimum value: %d\n", GetInt(GetMinValueInBST(bst)));
        printf("Maximum value: %d\n", GetInt(GetMaxValueInBST(bst)));
    // insert
    InsertValueInBST(bst, NewInt(7));
    InOrderTraversal(bst->tree, PrintIntTNode);
    // delete
    Int temp_int = NewInt(5);
    printf("\nfind 5: %s\n", GetEqualNodeHolderInBST(bst, temp_int) ? "yes" : "no");
    DeleteNodeInBST(bst, temp_int);
    printf("find 5 after delete: %s\n", GetEqualNodeHolderInBST(bst, temp_int) ? "yes" : "no");
    InOrderTraversal(bst->tree, PrintIntTNode);
    putchar('\n');
    // destuct temp_int and bst
    DeleteAndGetInt(temp_int);
    DeleteBST(bst);
}