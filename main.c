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
    prependNode(&head, createNode("Dog"));
    prependNode(&head, createNode("Monkey"));
    findNode(&head, "Goldfish");
    findNode(&head, "Bill");
    printf("Before delete Monkey:\n");
    printList(&head);
    printf("----\n");
    deleteNode(&head, "Monkey");
    printf("After delete Monkey:\n");
    printList(&head);
    printf("----\n");
    printf("Delete Pig...\n");
    deleteNode(&head, "Pig");
    printf("After delete Pig:\n");
    printList(&head);
    printf("----\n");
    puts("Append Axolotl:\n");
    appendNodeAlt2(&head, createNode("Axolotl"));
    // insertAlphabetically(&head, createNode("Spider"));
    // insertAlphabetically(&head, createNode("Rhino"));
    // insertAlphabetically(&head, createNode("Aardvark"));
    // insertAlphabetically(&head, createNode("Badger"));
    // insertAlphabetically(&head, createNode("Deer"));
    // insertAlphabetically(&head, createNode("Elephant"));
    printList(&head);
    return 0;
}
