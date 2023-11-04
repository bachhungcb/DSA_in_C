#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* makeNode(int v){
    Node* q = (Node*)malloc(sizeof(Node));
    q->value = v; q->next = NULL;
    return q;
}

Node* insert_Last(Node* h, int v){
    Node* p = h;
    if(h == NULL)
        return makeNode(v);

    while(p->next != NULL)
        p = p->next;

    Node* q = makeNode(v);
    p->next = q;
    
    free(p);
    return h;
}

Node* print_List(Node* h){
    Node* p = h;
    printf("[ ");
    if(h == NULL)
        return NULL;
    
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }

    printf("]");
    free(p);
    return h;
}

Node* sort(Node* list1, Node* list2){
    Node* p = list1;
    Node* q = list2;
    if(h = NULL)
        return NULL;

    if(p == NULL)
        return p;

    if(q == NULL)
        return q;

    
    
}

int main(){
    Node* head = NULL;
    head = insert_Last(head, 10);
    head = insert_Last(head, 9);
    head = insert_Last(head, 8);
    head = insert_Last(head, 7);
    head = insert_Last(head, 6);
    head = insert_Last(head, 5);
    head = insert_Last(head, 4);
    head = insert_Last(head, 3);
    head = insert_Last(head, 2);
    head = insert_Last(head, 1);

    print_List(head);
    free(head);
    return 0;
}