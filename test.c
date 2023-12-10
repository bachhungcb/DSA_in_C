#include <stdio.h>

unsigned int ham(unsigned int a, unsigned int b)
{
    if((a==0)||(b==0)) return 0;
    if(a>b) return ham(a-b,b);
    else if(a<b) return ham(a,b-a);
    else return a;  
}

int main(){
    printf("%d", ham());
    return 0;
}