#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value; //the node value
    struct Node *next; //pointer to the next node
}Node;

Node*makeNode(int v){//allocate memory for a new node
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; p->next = NULL;
}

