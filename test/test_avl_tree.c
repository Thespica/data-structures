#include "util.h"

#include "data-structures/tree/avl_tree.h"
#include "data-structures/util/generic.h"

int main(void) {
    TreeAVL tree = NewAVLTree(NewInt(1), IntCmp, IntEq);
    for (int i = 2; i < 10; ++i) {
        InsertValueIntoTreeAVL(tree, NewInt(i));
    }
    TraverseTreeAVL(tree->root, PrintIntTNodeWithDepth);
    DeleteTreeAVL(tree);
}
