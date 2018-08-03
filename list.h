#include "string.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    char *name;
    struct node *next;
} NODE;

NODE *createNode(char *name);
NODE *findNode(NODE **ppHead, char *name);
void appendNode(NODE **head, NODE *newNode);
void prependNode(NODE **head, NODE *newNode);
void appendNodeAlt(NODE **head, NODE *newNode);
void appendNodeAlt2(NODE **headRef, NODE *newNode);
int insertAlphabetically(NODE **headRef, NODE *newNode);
int deleteNode(NODE **head, char *nameForDeletion);
void printList(NODE **ppHead);
