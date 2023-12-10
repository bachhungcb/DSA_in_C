#include <stdio.h>
#include <stdlib.h>
#include "liet_ke_xau_nhi_phan.h"

int n;
int x[100];


void printSolution(){
    for(int i = 1; i<=n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

int check(int v, int k){
    return 1;
}

void Try(int k){
    for(int v = 0; v <=1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n) printSolution();
            else Try(k+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}