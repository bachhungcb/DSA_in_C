#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct SinhVien{
    char name[100];
    char email[100];
    struct SinhVien* next;
}Node;

Node* makeNode(char *ten, char *em){
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name, ten);
    strcpy(newnode->email, em);
    newnode->next = NULL;
    return newnode;
}

Node* insert_last(Node* h, char *ten, char *em){
    Node* p = h;
    if(h == NULL)
        return makeNode(ten, em);

    while(p->next != NULL)
        p = p->next;

    Node* q = makeNode(ten, em);
    p->next = q;
    return h;
}

Node* print_list(Node* h){
    Node* p = h;
    int i = 1;
    if(h == NULL){
        printf("Danh sach trong.");
        return NULL;
    }
    while(p != NULL){
        printf("Sinh vien thu %d\t:%s", i, p->name);
        printf("Email\t\t:%s\n", p->email);
        p = p->next;
        i++;
    }

    return h;
}

Node* remove_node(Node* h, char *ten){
    Node* p = h;
    Node* prev = NULL;
    if(h == NULL)
        return NULL;

    while(p != NULL){
        if(strcmp(p->name,ten) == 0) break;
        prev = p;
        p = p->next;
    }
    if(p!=NULL){
        if(prev == NULL){
            h = p->next;
        }else{
            prev->next = p -> next;
        }
    }
    return h;
}

Node* find_list(Node* h, char* ten){
    Node* p = h;
    Node* prev = NULL;
    if(h == NULL)
        return NULL;

    while(p->next != NULL && strcmp(p->name, ten) != 0)
        p = p->next;

    if(p->next != NULL){
        if(prev == NULL){
            printf("Ten sinh vien\t:%s\n", h->name);
            printf("Email\t:%s\n", h->email);
        }else{
            printf("Ten sinh vien\t:%s\n", p->name);
            printf("Email\t:%s\n", p->email);
        }
    }
    else{
        if(strcmp(p->name, ten) == 0){
            printf("Ten sinh vien\t:%s\n", p->name);
            printf("Email\t\t:%s\n", p->email);
        }else{
            printf("Khong tim thay sinh vien");
        }
    }

    return(h);
}
int menu(){
    system("cls");
    printf("Moi ban chon chuc nang.\n");
    printf("1. In danh sach sinh vien\n");
    printf("2. Them 1 ho so vao cuoi danh sach\n");
    printf("3. Xoa 1 ho so\n");
    printf("4. Tim kiem 1 ho so\n");
    printf("5. Thoat\n");
    int cn;
    scanf("%d", &cn);
    return cn;
}

int main(){
    Node* head = NULL;

    while (1){
        int cn = menu();
        switch (cn){
        case 1:
             system("cls");
             print_list(head);
             getch();
            break;
        case 2:
             system("cls");
             char ten_sinh_vien[100];
             char email_cua_sinh_vien[100];
             fflush(stdin);

             printf("Nhap vao ten sinh vien: ");
             fgets(ten_sinh_vien, 100, stdin);

             printf("Nhap vao email sinh vien: ");
             fgets(email_cua_sinh_vien, 100, stdin);
             head = insert_last(head, ten_sinh_vien, email_cua_sinh_vien);

             getch();
             break;

        case 3:
             system("cls");
             char ten_sinh_vien_xoa[100];
             fflush(stdin);

             printf("Nhap vao ten sinh vien muon xoa: ");
             fgets(ten_sinh_vien_xoa,100 ,stdin);

             head = remove_node(head, ten_sinh_vien_xoa);
             getch();
             break;

        case 4:
             system("cls");
             char ten_sinh_vien_tim[100];

             fflush(stdin);
             printf("Nhap vao ten sinh vien muon tim: ");
             fgets(ten_sinh_vien_tim,100 ,stdin);

             head = find_list(head,ten_sinh_vien_tim);
             getch();
             break;

         case 5:
            exit(0);
        }
    }

    free(head);
    return 0;
}
