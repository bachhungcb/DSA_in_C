#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;

typedef struct Node{
	int data;
	Node* next;
}Node;

Node* makeNode(int x){
	Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
	return newnode;
}

Node* addlast(Node* head, int x){
	Node* p = head;
	if(head == NULL) return makeNode(x);
	
	while(p->next != NULL){
		p = p->next;
	}
	
    Node* q = makeNode(x);
    p->next = q;
    return head;

}


Node* addfirst(Node* head,int x){
	Node* newNode = head;
	if (head == NULL) return makeNode(x);

	newNode->next = head;
	head = newNode;

    return head;
}

void addbefore(Node* head, int k, int x){
	Node* t = head;
	while(t->data != x && t->next != NULL){
		t = t->next;
	}
    if (t->next != NULL){
        Node* newNode = makeNode(k);
        Node* q = head; //?
        if (head == NULL) head = newNode;
        while(q->next != t){
            q = q->next;
        }
        q->next = newNode;
        newNode->next = t;
    }
	
}
void addafter(Node* head, int k, int x){
	Node* t = head;
	while (t->data != x && t->next != NULL){
		t = t->next;
	}
	if (t->next != NULL){
		Node* newNode = makeNode(k);
		Node* q = head;
		if (head == NULL) head = newNode;
		while(q != t) q = q->next;
		newNode->next = t->next;
		q->next = newNode;
	}
}

void Print(Node* head){
	Node* p = head;
	while (p->next != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void remove(Node* head, int x){
	Node* p = head;
	Node* q = head;
	while (p != NULL){
		if (p->data == x){
			Node* r = p;
			if (p == head){
				head = (head)->next;
				p = head;
				q = head;
			}
			else if (q->next->next == NULL) p->next = NULL;
			else {
				q->next = p->next;
				p = p->next;
			}
		}
		q = p;
		p = p->next;
	}
}

void reverse(Node* head){
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main(){
	int n;
	char choice[10];
	Node* head = NULL;
	cin >> n;
	for(int i = 0; i< n; i++)
	{
		int a;
		cin >> a;
		addlast(head, a);	
	}
	while(1)
	{
		cin >> choice;
		if (strcmp(choice, "#") == 0) break;
		if (strcmp(choice, "addlast") == 0){
			int v;
			cin >> v;
			Node* p = head;
			while(p->next != NULL){
				if(p->data == v) break;
				p = p->next;
				
			}
			if (p->next == NULL) addlast(head, v);
		}
		if(strcmp(choice,"addfirst") == 0){
			int v;
			cin >> v;
			Node* p = head;
			while(p->next != NULL){
				if(p->data == v) break;
				p = p->next;
			}
			if(p->next == NULL)
				addfirst(head,v);
		}
		if(strcmp(choice, "addafter") == 0){
			int v, b, count = 0;
			cin >> v >> b;
			Node* p = head;
			while(p != NULL){
				if(p->data == v) break;
				if(p->data == b) count++;
				p = p->next;
			}
			if(p == NULL && count != 0)
				addafter(head,v,b);
			
		}
		if(strcmp(choice, "addbefore") == 0){
			int v, b, count = 0;
			cin >> v >> b;
			Node* p = head;
			while(p != NULL){
				if(p->data == v) break;
				if(p->data == b) count++;
				p = p->next;
			}
			if(p == NULL && count != 0)
				addbefore(head,v,b);
		}
		if(strcmp(choice, "remove") == 0){
		
			int v;
			cin >> v;
			remove(head,v);
		}
		if(strcmp(choice, "reverse") == 0)
			reverse(head);
		
	}
	Print(head);
	return 0;
}