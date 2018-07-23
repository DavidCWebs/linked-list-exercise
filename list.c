#include "list.h"

NODE *createNode(char *name)
{
    NODE *p = malloc(sizeof(NODE));
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->next = NULL; // This will be set on insertion
    return p;
}

void appendNode(NODE **headRef, NODE *newNode)
{
    // Find the last NODE
    if (*headRef == NULL) {
        // If *headRef is NULL, the list is empty. Just set the correct address
        // value in *headRef (the pointee of head), and we're finished.
        *headRef = newNode;
    } else {
        NODE *tracer = *headRef;
        NODE *tmp = NULL;
        while (tracer != NULL) {
            tmp = tracer;
            tracer = tracer->next;
        }
        // tmp is now the last node in the list. Point it to newNode.
        tmp->next = newNode;
    }
}

void appendNodeAlt(NODE **headRef, NODE *newNode)
{
    NODE **tracer = headRef; // initially refers to the address of head
    while (*tracer) {
        // Set `tracer` to the address of the pointer to the next `NODE`. In the
        // case of an empty list or the last `NODE`, this value will be `NULL`.
        // NOTE: `*tracer` dereferences `tracer` once, so it refers to a pointer
        // to a `NODE`. The arrow operator can then be used to indirectly access
        // the member variable. This would be the equivalent without the arrow
        // operator: `tracer = &(*(*tracer)).next;`, or `tracer = &(**tracer).next;`.
        // `tracer` must be a pointer to a pointer to a `NODE` - it must contain
        // the memory address of a pointer to a `NODE` (i.e. `NODE *`).
        tracer = &(*tracer)->next;
        // Equivalents:
        // tracer = &(**tracer).next;
        // tracer = &(*(*tracer)).next;
    }
    // After the loop, *tracer will be a pointer to NULL even if the list is empty.
    newNode->next = *tracer;

    // *tracer now refers to the pointer to the next node of the last node.
    // Currently NULL, the next line refers it to the new `NODE`.
    *tracer = newNode;
}

void prependNode(NODE **head, NODE *newNode)
{
    newNode->next = *head;
    *head = newNode;
}

int insertAlphabetically(NODE **headRef, NODE *newNode)
{
    NODE **tracer = headRef;
    // `tracer` now holds the address of the head pointer, which in turn points
    // to the head of the list. `*tracer` refers to the address of the head `NODE`.
    // NOTE: amending `*tracer` changes the head reference, because you're
    // amending the address held by `head`.

    while (*tracer && (strcmp((*tracer)->name, newNode->name) < 1)) {
        printf("*tracer->next->name = %s\n", (*tracer)->next->name);
        // set tracer to the address of the next node.
        tracer = &(*tracer)->next;
    }
    // tracer now refers to the endpoint for insertion
    printf("current: %s\n", (*tracer)->name);
    return 0;
}

void deleteNode(NODE *pNodeForDeletion)
{
    printf("%s\n", pNodeForDeletion->name);
}
void printList(NODE **ppHead)
{
    NODE **tracer = ppHead;
    while(*tracer) {
        printf("%s\n", (*tracer)->name);
        tracer = &(*tracer)->next;
    }
}
