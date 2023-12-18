#include "util.h"

#include "data-structures/queue/queue.h"
#include "data-structures/util/generic.h"

int main(void) {
    Queue queue = NewQueue();
    for (int i = 0; i < 10; i++) {
        EnQueue(queue, NewInt(i));
    }
    printf("Queue capacity: %zu\n", GetQueueSize(queue));
    TraverseQueue(queue, PrintIntNode);
    printf("\nDe queue value: %d\n", DeleteAndGetInt(DeQueue(queue)));
    printf("De queue value: %d\n", DeleteAndGetInt(DeQueue(queue)));
    TraverseQueue(queue, PrintIntNode);
    printf("\nEn queue value: 100\n");
    EnQueue(queue, NewInt(100));
    TraverseQueue(queue, PrintIntNode);
    DeleteQueue(queue);
    return 0;
}