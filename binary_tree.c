#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root;

Node* makeNode(int id){
    Node *p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}

Node* find (Node *r, int id){
    if(r == NULL)return NULL;
    if(r->id == id) return r;
    Node* p = find(r->leftChild, id);
    if(p != NULL)return p;
    return find(r->rightChild, id);
}

void addLeftChild(int u, int left){
    Node *pu = find(root,u);

    if(pu == NULL){
        printf("Khong tim thay node %d\n", u); return;
    }

    if(pu->leftChild != NULL){
        printf("Node %d da co leftChild\n", u);
        return;
    }

    pu->leftChild = makeNode(left);
}

void addRightChild(int u, int right){
    Node *pu = find(root, u);

    if(pu == NULL){
        printf("Khong tim thay node %d", u);
        return;
    }

    if(pu->rightChild != NULL){
        printf("Node %d da co rightChild\n", u);
        return;
    }

    pu->rightChild = makeNode(right);
}

void printTree(Node *r){
    if(r == NULL)return;
    printf("%d: ", r->id);
    if(r->leftChild == NULL) printf("LeftChild = -1\n");
    else printf("LeftChild = %d\n", r->leftChild->id);
    if(r->rightChild == NULL) printf("RightChild = -1\n");
    else printf("RightChild = %d\n", r->rightChild->id);
    printf("\n");

    printTree(r->leftChild);
    printTree(r->rightChild);
}

void printChildren(Node *p){
    if(p->leftChild == NULL) printf("This node %d doesn't have LeftChild",p->id);
    else printf("LeftChild = %d\n", p->leftChild->id);

    if(p->rightChild == NULL) printf("This node %d doesn't have RightChild", p->id);
    else printf("RightChild = %d\n", p->rightChild->id);
}

void processFind(){
    int id;
    printf("Nhap vao node can tim");
    scanf("%d", &id);
    Node *p = find(root, id);
    if(p == NULL){
        printf("Khong tim thay node %d\n", id);
    }else{
        printf("Tim thay node %d\n", id);
        printChildren(p);
    }
}

void printTheWholeTree(){
    printTree(root);
}

void processAddLeftChild(){
    int id,u;
    printf("Nhap node can them va leftChild cua node do: ");
    scanf("%d %d", &u,&id);
    addLeftChild(u,id);
}

void processAddRightChild(){
    int id, u;
    printf("Nhap node can them va RightChild cua node do: ");
    scanf("%d %d", &u, &id);
    addRightChild(u,id);
}

int height(Node *p){
    if(p == NULL) return 0;
    int maxH = 0;
    int hl = height(p->leftChild);
    if(maxH < hl) maxH = hl;
    int hr = height(p->rightChild);
    if(maxH < hr) maxH = hr;
    return maxH + 1;
}

void processHeight(){
    int id;
    printf("Nhap vao so id cua node can tim: ");
    scanf("%d", &id);
    Node *p = find(root,id);
    if(p == NULL)printf("Khong tim thay node %d trong cay", id);
    else printf("Chieu cao cua node %d la: %d\n", id, height(p));
}

int count(Node *p){
    if(p==NULL) return 0;
    return 1 + count(p->leftChild) + count(p->rightChild);
}

void printLeaves(Node *p){
    if(p == NULL)return;
    if(p->leftChild == NULL && p->rightChild == NULL)
        printf("%d", p->id);
    printLeaves(p->leftChild);
    printLeaves(p->rightChild);
}

void procressPrintLeaves(){
    printLeaves(root); printf("\n");
}

void processCount(){
    printf("So luong node co trong cay la: %d", count(root));
}

void freeTree(Node* r){
    if(r==NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r); r = NULL;
}

int main(){
    root = makeNode(1);
    addLeftChild(1, 2);
    addRightChild(1, 3);
    addLeftChild(2,4);
    addLeftChild(3,5);
    printTheWholeTree(root);
    freeTree(root);
    return 0;
}