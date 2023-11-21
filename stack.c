#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char cha;
    struct Node* next;
}Node;

Node* top;

void initStack(){
    top = NULL;
}

int stackEmpty(){
    return top == NULL;
}

Node* makeNode(char c){
    Node *p = (Node*)malloc(sizeof(Node));
    p->cha = c;
    p->next = NULL;
    return p;
}

void push(char x){
    Node* p = makeNode(x);
    p->next = top;
    top = p;
}

char pop(){
    if(stackEmpty())
        return ' ';
    char x = top->cha;
    Node* temp = top;
    top = temp->next;
    free(temp);
    return x;
}

void printList(){
    for(Node *p = top; p != NULL;p = p->next)
        printf("%c", p->cha);
}

int main(){
    Node* stack = NULL;
    initStack();
    char my_string[100];
    push('c');
    push('h');
    push('a');
    push('o');
    push('!');
    
    printList();
    printf("\n%c\n", pop());
    printList();
    
    free(stack);
    return 0;
}
