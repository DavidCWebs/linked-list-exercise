#include "list.h"
#include "stdio.h"

int main()
{
    NODE *head = malloc(sizeof(NODE));
    head = NULL;
    // appendNode(&head, createNode("Honey Badger"));
    // appendNode(&head, createNode("Rabbit"));
    // appendNodeAlt(&head, createNode("Dog"));
    // appendNodeAlt(&head, createNode("Cat"));
    prependNode(&head, createNode("Goldfish"));
    prependNode(&head, createNode("Pig"));
    // insertAlphabetically(&head, createNode("Spider"));
    // insertAlphabetically(&head, createNode("Rhino"));
    // insertAlphabetically(&head, createNode("Aardvark"));
    // insertAlphabetically(&head, createNode("Badger"));
    // insertAlphabetically(&head, createNode("Deer"));
    // insertAlphabetically(&head, createNode("Elephant"));
    printList(&head);
    return 0;
}
