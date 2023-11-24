#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdbool.h>

#ifndef SINGLE_LINKED_LIST_ELEMENT_TYPE
#define SINGLE_LINKED_LIST_ELEMENT_TYPE int
#endif

/**
 * @brief The node of single linked list
 * @param value Value of node
 * @param next Pointer to next node
 */
typedef struct node {
    SINGLE_LINKED_LIST_ELEMENT_TYPE value;
    struct node *next;
} Node;

typedef Node *SingleLinkedList;

/**
 * @brief Construct a single linked list
 * @return Head pointer of single linked list
 */
SingleLinkedList ConstructSLL(void);

/**
 * @brief Get node at position
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 * @return Node pointer
 */
Node *GetNodeAtSLL(SingleLinkedList head, unsigned int position);

/**
 * @brief Delete node at position
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 */
void DeleteNodeAtSLL(SingleLinkedList head, unsigned int position);

/**
 * @brief Get number of nodes
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 * @return Number of nodes
 */
int GetNodesNumSLL(const SingleLinkedList head);

/**
 * @brief Insert a new node at position, begin with 1
 * @param head Head pointer of single linked list
 * @param position Position of node, begin with 1
 * @param value Value of node to be inserted
 */
void InsertNodeAtSLL(SingleLinkedList head, unsigned int position, SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * @brief Insert a new node at tail
 * @param head Head pointer of single linked list
 * @param value Value of node to be inserted
 */
void TailInsertSLL(SingleLinkedList head, SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * @brief Insert a new node at head
 * @param head Head pointer of single linked list
 * @param value Value of node to be inserted
 */
void HeadInsertSLL(SingleLinkedList head, SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * @brief Print the single linked list
 * @param head Head pointer of single linked list
 */
void PrintSLL(SingleLinkedList head);

/**
 * @brief  Delete the first nodes with value
 * @param head Head pointer of single linked list
 * @param value Value of node to be deleted
 * @return Whether the node is deleted
 */
bool DeleteFirstValueInSLL(SingleLinkedList head, SINGLE_LINKED_LIST_ELEMENT_TYPE value);

/**
 * @brief Delete the single linked list, then set pointer on stack to NULL
 * @param head Head pointer of single linked list
 */
void DestructSLL(SingleLinkedList *head);

#endif // SINGLE_LINKED_LIST_H