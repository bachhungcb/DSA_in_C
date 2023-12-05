#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[256];
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Node; 
Node* root;

Node* makeNode(char *name){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy (p->name,name);
    p->leftMostChild = NULL; p->rightSibling = NULL;
    return p;
}


Node* find(Node* r, char *name){
    if(r == NULL) return NULL;
    if(strcmp(r->name,name) == 0) return r;
    Node *p = r->leftMostChild;

    while(p != NULL){
        Node *q = find(p, name);
        if(q != NULL) return q;
        p = p->rightSibling;
    }
}

Node* addLast(Node *p, char *name){
    if(p==NULL) makeNode(name);
    p->rightSibling = addLast(p->rightSibling, name);
    return p;
}

void addChild(char *name, char *child){
    Node* r = find(root, name);
    if(r = NULL) return;
    r->leftMostChild = addLast(r->leftMostChild,child);
}

void printTree(Node* r){
    if(r == NULL) return;
    printf("%s->", r->name);
    Node *p = r->leftMostChild;

    while(p != NULL){
        printf("%s->", p->name);
        p = p->rightSibling;
    }

    printf("\n");
    p = r->leftMostChild;
    while (p != NULL){
            printTree(p);
            p = p->rightSibling;
    }
}

void processFind(){
    char name[256]; scanf("%s", name);
    Node*p = find(root,name);
    if( p == NULL) printf("Khong tim thay %s", name);
    else printf("Tim thay %s", name);
}

void processFindChild(){
    char name[256]; scanf("%s", name);
    Node *p = find(root, name);
    if(p == NULL) printf("Khong tim thay %s", name);
    else{
        printf("Tim thay ten %s", name);
        Node *q = p->leftMostChild;
        while(q != NULL){
            printf("%s->", q->name); q = q->rightSibling;
        }
    }
    printf("\n");
}

int height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    Node *q = p->leftMostChild;

    while(q != NULL){
        int h = height(q);
        maxH = maxH < h? h: maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

void processHeight(){
    char name[256];
    scanf("%s", name);
    Node *q = find(root, name);
    if(q == NULL) printf("Khong tim thay ten %s", name);
    else{
        printf("Tim thay ten %s voi do cao %d\n", name, height(q));
    }   
}

int count(Node* r){
    if(r == NULL) return 0;
    int cnt = 1;
    Node *q = r->leftMostChild;
    while (q != NULL){
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}

void processCount(){
    pritnf("So node cua cay la: %d\n", count(root));
}

void freeTree(Node* r){
    if(r == NULL)return;
    Node *q = r->leftMostChild;
    while(q != NULL){
        Node *sp = q ->rightSibling;
        free(q);
        q = sp;
    }
    printf("Da giai phong node: %s\n", r->name); free(r);
    r = NULL;
}


int main(){
    return 0;
}