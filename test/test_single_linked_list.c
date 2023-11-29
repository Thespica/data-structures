#include <stdio.h>

#include "util.h"

#include "data-structures/list/single_linked_list.h"
#include "data-structures/util/generic.h"

int main(void) {
    SingleLinkedList list = NewSLL();
    for (int i = 0; i < 10; i++) {
        TailInsertSLL(list, NewInt(i));
    }
    printf("Size: %zu\n", GetSizeSLL(list));
    TraverseSLL(list, PrintIntNode);
    printf("\nSet value of the 5th node to 100:\n");
    SetInt(GetNodeAtSLL(list, 5)->value, 100);
    TraverseSLL(list, PrintIntNode);
    DeleteNodeAtSLL(list, 5);
    putchar('\n');
    printf("Size after delete one node: %zu\n", GetSizeSLL(list));
    TraverseSLL(list, PrintIntNode);
    DeleteSLL(list);
    return 0;
}
