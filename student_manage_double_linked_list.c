#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[256];
    char email[256];
    struct Node* next;
    struct Node* prev;
}Node;

Node* first, *last;

Node* makeNode(char *name, char *email){
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name, name);
    strcpy(newnode->email, email);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void initList(){
    first = NULL; last = NULL;
}

int emptyList(){
    return first == NULL && last == NULL;
}

void printRight2Left(){
    for(Node* p = first; p != NULL; p = p->next){
        printf("Ten sinh vien: %s\n", p->name);
        printf("Email sinh vien: %s\n", p->email);
    }
}

void printLeft2Right(){
    for(Node *p = last; p != NULL; p = p ->prev){
        printf("Ten sinh vien: %s\n", p->name);
        printf("Email sinh vien: %s\n", p->email);
    }
}

void insertLast(char *name, char *email){
    Node* p = makeNode(name, email);
    if(emptyList()){
        first = p; last = p;
    }else{
        last->next = p; p->prev = last;
        last = p;
    }
}

Node* findProfile(char *name){
    for(Node* p = first; p!=NULL; p=p->next) {
        if(strcmp(p->name, name) == 0)
            return p;
    }
    return NULL;
}

void deleteProfile(char *name){
    Node *p = first;

    if(!findProfile(name)){ 
            printf("Khong tim thay ho so can tim");
            return;
    }else{

        Node* left = p->prev;
        Node* right = p->next;
        if(left != NULL)left->next = right;
        if(right != NULL)right->prev = left;
        if(left == NULL) first = right;
        if(right == NULL) last = left;
    }
    free(p);
}

void searchProfile(char *name){
    Node *p = findProfile(name);
    printf("Ten sinh vien: %s\n", p->name);
    printf("Email sinh vien: %s", p->email);
    free(p);
}

int main(){
    Node* head = NULL;
    initList();
    insertLast("Bach","123");
    insertLast("Dang","456");
    insertLast("Duy","897");

    searchProfile("Bach");

    while (head != NULL)
    {
        Node* temp = head->next;
        free(head);
        head = temp;
    }
    return 0; 
}