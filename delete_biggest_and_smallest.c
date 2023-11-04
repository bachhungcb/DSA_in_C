#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node*makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; p->next = NULL;
    return p;
}

Node* insert_Last(Node* h, int v){
    Node* p = h;
    if(h == NULL)
        return makeNode(v);
    
    while(p->next != NULL)
        p = p->next;
    
    Node* q = makeNode(v);
    p->next = q;
    return h;
}

Node* print_list(Node* h){
    Node* p = h;
    if(h = NULL)
        return NULL;

    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }

    return h;
}

Node* remove_Node(Node* h, int v){
    Node* p = h;
    Node* prev = NULL;
    if(h == NULL)
        return NULL;
    
    while(p != NULL){
        if(p->value == v) break;
        p = p->next;
    }

    if(p->next != NULL){
        if(prev != NULL){
            prev->next = p->next;
        }else{
            h = p->next;
        }
    }

    free(p);
    return h;
}

Node* remove_Biggest(Node* h){
    Node* p = h;
    if(h == NULL)
        return NULL;
    int max = 0;
    while(p != NULL){
        if(p->value > max)
            max = p->value;
        p = p->next;
    }
    
    return remove_Node(h, max);
}

int main(){
    Node* head = NULL;
    head = insert_Last(head, 5);
    head = insert_Last(head, 4);
    head = insert_Last(head, 3);
    head = insert_Last(head, 2);
    head = insert_Last(head, 1);

    print_list(head);
    head = remove_Biggest(head);
    printf("\n");
    print_list(head);
    return 0;
}