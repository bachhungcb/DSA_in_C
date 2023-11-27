#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node{
    int row,col; //chi so hang va so cot hien tai
    int step;    //chi so buoc hien tai
    struct Node* next;
    struct Node* prarent; 
}Node;

Node* head, *tail;

Node* listNode[MAX*MAX];
int szlist = 0;

int n,m; //mecung NxM
int r0,c0;
int visited[MAX][MAX];

const int dr[4] = {1, -1, 0, 0}; //do lech giua cac hang
const int dc[4] = {0, 0, 1, -1}; //do lech giua cac cot

Node* finalNode;

Node* makeNode(int row, int col, int step, Node* parent){
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row; node->col = col; node->next = NULL;
    node->prarent = parent; node->step = step;
    return node;
}

void initQueue(){
    head == NULL; tail == NULL;
}

int emptyQueue(){
    return head == NULL && tail == NULL;
}

void pushQueue(Node* node){
    if(emptyQueue()){
        head = node; tail = node;
    }else{
        tail->next = node; tail = node;
    }
}

Node* popQueue(){
    if(emptyQueue()) return NULL;
    Node* node = head; head = node->next;
    if(head == NULL) tail = NULL;
    return node;
}

int A[6][6] = {
        {2, 2, 2, 2, 1, 2},
        {2, 0, 0, 0, 1, 2},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 3, 1},
        {1, 1, 1, 1, 1, 1}
    };

int legal(int row, int col){
    return A[row][col] != 1 && !visited[row][col];
}


int target(int row, int col){
    return row < 1 || row > n || col < 1 || col > m;
}

void finalize(){
    for(int i = 0; i < szlist; i++)
        free(listNode[i]);

    // Free memory of linked list nodes
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}


void addList(Node* node){
    listNode[szlist] = node;
    szlist++;
}

int main(){
    n = m = 6;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            visited[r][c] = 0;
        }
    }

    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(A[r][c] == 3){
                r0 = r;
                c0 = c;
            }
        }
    }

    initQueue();
    Node* startNode = makeNode(r0, c0, 0, NULL);
    addList(startNode);
    pushQueue(startNode);
    visited[r0][c0] = 1;
    while(!emptyQueue()){
        Node* node = popQueue();
        printf("POP (%d,%d)\n", node->col, node->row);
        for(int k = 0; k < 4; k++){
            int nr = node->row + dr[k];
            int nc = node->col + dc[k];
            if(legal(nr,nc)){
                visited[nr][nc] = 1;
                Node* newNode = makeNode(nr,nc,node->step+1, node);
                addList(newNode);
                if(target(nr,nc)){
                    finalNode = newNode; break;
                }else{
                    pushQueue(newNode);
                }
            }
        }
        if(finalNode != NULL) break; //found solution
    }

    Node* s = finalNode;
    while (s!=NULL)
    {
        printf("(%d, %d)", s->row,s->col);
        s = s->prarent;
    }
    finalize();
}
