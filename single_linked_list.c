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

Node* insertLast(Node* h, int v){ //Node *h is the pointer point to the header of the linked list
    Node* p = h;
    if(h == NULL)
        return makeNode(v);
    
    //general case
    while (p->next != NULL)
        p = p->next;

    Node* q = makeNode(v);
    p->next = q;
    return h;
}

