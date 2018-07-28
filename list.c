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

/**
 * Insert a node into the list, in alphabetic order based on the `name` member
 * variable.
 *
 * This function doesn't sort the list - it just inserts the new node at the
 * first available position where the name of the following node is alphabetically
 * greater.
 * @param  headRef [description]
 * @param  newNode [description]
 * @return         [description]
 */
int insertAlphabetically(NODE **headRef, NODE *newNode)
{
    NODE **tracer = headRef;
    // The variable `tracer` now holds the address of the head pointer, which in
    // turn points to the head of the list - it holds the memory address of the
    // first node if there is one, and `NULL` if there is not.
    // At this point, `*tracer` is the address of the head `NODE` (or NULL). It
    // is a `NODE *` to the first node in the list. NOTE: amending `*tracer`
    // changes the head reference in the caller function, because you're
    // amending the address held by `head`. This is the whole point of using the
    // double pointer technique. Because this function receives an address of a
    // pointer - a double pointer, or pointer-to-pointer - we can access that
    // memory location - substituting the pointer to point to a different node
    // as required by simply setting `*tracer` to the memory address of the
    // required node.

    while (*tracer && (strcmp((*tracer)->name, newNode->name) < 1)) {
    // while (*tracer) {
        printf("*tracer->name = %s\n", (*tracer)->name);
        // set tracer to the address of the next node.
        tracer = &(*tracer)->next;
    }
    // `tracer` now refers to the endpoint for insertion - `tracer` is a pointer
    // to a pointer to the NODE after the new node's final inserted position.
    // In other words, `tracer` contains the address of a pointer variable, which
    // in turn contains the address of the NODE that the new node should be
    // inserted before (or NULL if it's the last node in the list).
    // De-referencing tracer provides the address of what should be the following
    // node.
    newNode->next = *tracer;

    // First attempt: (*tracer)->next = newNode; this is wrong and will cause a
    // segmentation fault in the case of the last element, since
    // (*tracer)->next is NULL.
    //
    // `tracer` contains the address of the `next` member variable of the
    // preceding node - which is a `NODE*` pointer, containing the address of the
    // next node. By dereferencing this we can amend the node which this points
    // to - it should be a pointer to the new node.
    *tracer = newNode;

    return 0;
}

void prependNode(NODE **head, NODE *newNode)
{
    newNode->next = *head;
    *head = newNode;
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
