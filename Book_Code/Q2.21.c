#include<stdio.h>

int fun1(unsigned word)
{
    return (int)((word<<24)>>24);
}

int fun2(unsigned word)
{
    return ((int)word<<24)>>24;
}


int main()
{
    printf("fun1(127) = %x\n", fun1(127));
    printf("fun2(127) = %x\n", fun2(127));
    printf("fun1(128) = %x\n", fun1(128));
    printf("fun2(128) = %x\n", fun2(128));
    printf("fun1(255) = %x\n", fun1(255));
    printf("fun2(255) = %x\n", fun2(255));
    printf("fun1(256) = %x\n", fun1(256));
    printf("fun2(256) = %x\n", fun2(256));
    return 0;
}