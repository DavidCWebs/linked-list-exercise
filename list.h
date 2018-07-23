#include "string.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    char *name;
    struct node *next;
} NODE;

NODE *createNode(char *name);
void appendNode(NODE **head, NODE *newNode);
void prependNode(NODE **head, NODE *newNode);
void appendNodeAlt(NODE **head, NODE *newNode);
int insertAlphabetically(NODE **headRef, NODE *newNode);
void deleteNode(NODE *pNodeForDeletion);
void printList(NODE **ppHead);
