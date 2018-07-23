#include "list.h"
#include "stdio.h"

int main()
{
    NODE *head = malloc(sizeof(NODE));
    head = NULL;
    appendNode(&head, createNode("Burgers"));
    appendNode(&head, createNode("Tequila"));
    appendNodeAlt(&head, createNode("Zuccini"));
    appendNodeAlt(&head, createNode("Bananas"));
    prependNode(&head, createNode("Avocados"));
    prependNode(&head, createNode("Beer"));
    insertAlphabetically(&head, createNode("Chorizo"));
    printList(&head);
    return 0;
}
