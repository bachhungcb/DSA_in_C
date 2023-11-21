#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* first, *last;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void initList(){
    first = NULL;
    last = NULL;
}

int listEmpty(){
    return first == NULL && last == NULL;
}

void printListRight2Left(){
    for(Node* p = first; p != NULL; p = p->next)
        printf("%d ", p->data);
}

void printListLeft2Right(){
    for(Node* p = last; p != NULL; p = p->prev)
        printf("%d ", p->data);
}

void insertLast(int v){
    Node* p = makeNode(v);
    if(listEmpty()){
        first = p; last = p;
    }else{
        last->next = p;
        p->prev = last;
        last = p;
    }
}

int main(){
    initList();
    Node* head = NULL;
    insertLast(6);
    insertLast(5);
    insertLast(4);
    insertLast(3);
    insertLast(2);
    insertLast(1);
    printListLeft2Right();
    printf("\n");
    printListRight2Left();
    free(head);
    return 0;
}