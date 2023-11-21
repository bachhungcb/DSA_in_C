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

int kiem_tra(char a, char b){
    if(a == '(' && b ==')') return 1;
    if(a == '[' && b ==']') return 1;
    if(a == '{' && b =='}') return 1;
    return 0;
}

int check(char* s){
    for(int i = 0; s[i] != 0; i++){

        if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
            push(s[i]);
        }else{
            if(stackEmpty()){
                return 0;
            }
            char x = pop();
            if(!kiem_tra(x,s[i])){
                return 0;
            }
        }
   }

   return stackEmpty();
}

int main(){
    initStack();
    char my_string[100];
    
    scanf("%s", my_string);

    printf("%d", check(my_string));

    while(top!= NULL)
        pop();

    return 0;
}
