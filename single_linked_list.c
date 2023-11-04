#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }

    return h;
}

Node* remove_All(Node* h, int v) {
    // Base case: If the list is empty, return NULL.
    if (h == NULL) {
        return NULL;
    }

    // If the current node's value matches v, remove it and continue.
    if (h->value == v) {
        Node* tmp = h;
        h = h->next;
        free(tmp);
        h = remove_All(h, v);  // Recursively continue to remove other elements with value v.
        return h;
    }

    // If the current node's value does not match v, recursively process the next node.
    h->next = remove_All(h->next, v);

    return h;  // Return the modified list.
}


Node* reverse_list(Node* h){
    Node* current = h;
    Node* next_pos = NULL;
    Node* previous = NULL;

    while(current != NULL){
        next_pos = current->next;
        current->next = previous;
        previous = current;
        current = next_pos;
    }
    h = previous;
    return h;
}

Node* add_First(Node* head, int v){
	if (head == NULL) return makeNode(v);

    Node* newNode = makeNode(v);
	newNode->next = head;
	head = newNode;

    return head;
}

Node* add_Before(Node* h, int x,int v){
    Node* p = h;

    if(h == NULL)
        return makeNode(v);
    
    while(p->next->value != v)
        p = p->next;

    Node* q = makeNode(x);
    q->next = p->next;
    p->next = q;

    return h;
}

Node* add_After(Node* h, int x,int v){
    Node* p = h;

    if(h == NULL)
        return makeNode(v);
    
    while(p->value != v && p->next != NULL)
        p = p->next;

    Node* q = makeNode(x);
    q->next = p->next;
    p->next = q;

    return h;
}

int check_value(Node* h, int value){
    Node* ptr = h;
    while(ptr != NULL){
        if(ptr->value == value){
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}


int main(){
    Node* q = NULL;
    int n;
    char choice[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        q = insert_Last(q, num);
    }
    
     while (1){
        scanf("%s", choice);

        if(strcmp(choice, "addlast") == 0){
            int value;
            scanf("%d", &value);
            if(check_value(q,value) == 0){
                insert_Last(q,value);
            }
        }

        if(strcmp(choice, "addfirst") == 0){
            int value;
            scanf("%d", &value);
            if(check_value(q,value) == 0){
                q = add_First(q, value);
            }
        }

        if(strcmp(choice, "addafter") == 0){
            int value, add;
            scanf("%d %d", &add, &value);
            if(check_value(q,value) == 1 && check_value(q,add) == 0){
                q = add_After(q, add, value);
            }
        }
        
        if(strcmp(choice, "addbefore") == 0){
            int value, add;
            scanf("%d %d", &add, &value);
            if(check_value(q,value) == 1 && check_value(q,add) == 0){
            q = add_Before(q, add, value);
            }
        }

        if(strcmp(choice, "remove") == 0){
            int value;
            scanf("%d", &value);
            q = remove_All(q, value);
        }

        if(strcmp(choice, "reverse") == 0){
            q = reverse_list(q);
        }

        if(strcmp(choice, "#") == 0){
            break;
        }
     }
     

    print_List(q);
    free(q);
    return 0;
}
