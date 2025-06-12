#include<stdio.h>

int main()
{
    int E[10]={1,2,3,4,5,6,7,8,9,10};
    int a=*(&E[3]+3);
    printf("%d",a);
    return 0;
}