#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a[100];
    int n; 
    printf("Nhap vao so n:");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        if(a[i] > a[i+1]){
            swap(&a[i], &a[i+1]);
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}