#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int value; //the node value
    struct Node *next; //pointer to the next node
}Node;

Node*makeNode(int v){//allocate memory for a new node
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v; p->next = NULL;
    return p;
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

Node* removeFirst(Node* h, int v){ //Node *h is the pointer point to the header of the linked list
    Node* p = h;
    if(h == NULL)
        return NULL;
    
    //general case
    while(p->next != NULL){
        if(p->value == v) break;
        p = p->next;
    }

    if(p->next != NULL){
        Node* q = p->next; p->next = q->next; free(q);
    }

    return h;
}

int count_Node (Node* h){
    int number_of_node = 0;
    Node* p = h;
    while (p->next != NULL){
        p = p->next;
        number_of_node++;
    }
    return number_of_node;
}

Node* print_List(Node* h){
    Node* p = h;
    if(h == NULL)
        return NULL;
    
    while(p->next != NULL){
        p = p->next;
        printf("%d ", p->value);
    }

    return h;
}

int main(){
    Node* q = insertLast(q, 6);
    insertLast(q, 9);
    //printf("%d \n", count_Node(q));
    print_List(q);
    return 0;
}
