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

Node* insert_Last(Node* h, int v){ //Node *h is the pointer point to the header of the linked list
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

Node* remove_Node(Node* h, int v){ //Node *h is the pointer point to the header of the linked list
    Node* p = h;
    if(h == NULL)
        return NULL;
    
    //general case
    while(p->next != NULL){
        if(p->next->value == v) break;
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

Node* remove_All(Node* h, int v){
    Node* p = h;
    if(h == NULL)
        return NULL;
    
    while(p->next != NULL){
        if(p->next->value == v){
            Node* q = p->next;
            p->next = q->next;
            free(q);
        }
        p = p->next;
    }

    return h;
}

int main(){
    Node* q = insert_Last(q, 6);
    insert_Last(q, 9);
    insert_Last(q, 1);
    insert_Last(q, 4);
    insert_Last(q, 6);
    insert_Last(q, 5);
    insert_Last(q, 10);
    //test chuong trinh

    print_List(q);
    printf("\n");
    remove_All(q, 6);
    printf("\n");
    print_List(q);
    
    return 0;
}
