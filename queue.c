#include <stdio.h>
#include <stdlib.h>

int kiem_tra[100][100] = {0};

typedef struct Node {
    int cot;
    int hang;
    struct Node* next;
} Node;

Node* queue = NULL;

Node* makeNode(int v, int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->hang = v;
    p->cot = x;
    p->next = NULL;
    return p;
}

Node* enqueue(Node* h, int ha, int c) {
    Node* p = h;
    if (h == NULL)
        return makeNode(ha, c);

    while (p->next != NULL)
        p = p->next;

    Node* q = makeNode(ha, c);
    p->next = q;
    return h;
}

void printList(Node* h) {
    Node* p = h;
    while (p != NULL) {
        printf("%d %d", p->hang, p->cot);
        p = p->next;
    }
}

Node* dequeue(Node* h) {
    if (h == NULL)
        return NULL;

    Node* temp = h;
    Node* newHead = temp->next;
    free(temp);
    return newHead;
}

int emptyQueue() {
    return queue == NULL;
}

int main() {
    int me_cung[6][6] = {
        {2, 2, 2, 2, 1, 2},
        {2, 0, 0, 0, 1, 2},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 3, 1},
        {1, 1, 1, 1, 1, 1}
    };
    int mt_di[6][6] = {0};

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (me_cung[i][j] == 3) {
                queue = enqueue(queue, i, j);
                kiem_tra[i][j] = 1;
            }
        }
    }

    while (!emptyQueue()) {
        Node* current = queue;
        queue = dequeue(queue);
        int currentHang = current->hang;
        int currentCot = current->cot;

        mt_di[currentHang][currentCot] = 1;

        // Check and enqueue neighboring cells
        if (currentHang - 1 >= 0 && me_cung[currentHang - 1][currentCot] == 0 && kiem_tra[currentHang - 1][currentCot] == 0) {
            queue = enqueue(queue, currentHang - 1, currentCot);
            kiem_tra[currentHang - 1][currentCot] = 1;
        }
        if (currentHang + 1 < 6 && me_cung[currentHang + 1][currentCot] == 0 && kiem_tra[currentHang + 1][currentCot] == 0) {
            queue = enqueue(queue, currentHang + 1, currentCot);
            kiem_tra[currentHang + 1][currentCot] = 1;
        }
        if (currentCot - 1 >= 0 && me_cung[currentHang][currentCot - 1] == 0 && kiem_tra[currentHang][currentCot - 1] == 0) {
            queue = enqueue(queue, currentHang, currentCot - 1);
            kiem_tra[currentHang][currentCot - 1] = 1;
        }
        if (currentCot + 1 < 6 && me_cung[currentHang][currentCot + 1] == 0 && kiem_tra[currentHang][currentCot + 1] == 0) {
            queue = enqueue(queue, currentHang, currentCot + 1);
            kiem_tra[currentHang][currentCot + 1] = 1;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", mt_di[i][j]);
        }
        printf("\n");
    }

    return 0;
}
