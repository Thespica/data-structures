#include <stdio.h>

#define SINGLE_LINKED_LIST_ELEMENT_TYPE int
#include "data-structures/linear/single_linked_list.h"

int main(void) {
    SingleLinkedList list = ConstructSingleLinkedList();
    for (int i = 0; i < 10; i++) {
        HeadInsert(list, i);
    }
    PrintSingleLinkedList(list);
    printf("%s\n", DeleteNodesAfter(list, 3) ? "success deleted" : "failed deleted");
    PrintSingleLinkedList(list);
    DestructSingleLinkedList(list);
    return 0;
}