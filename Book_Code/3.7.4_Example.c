#include<stdio.h>

int swap_Add(int* xp,int* yp)
{
    int x=*xp;
    int y=*yp;

    *xp=y;
    *yp=x;

    return x+y;
}

int caller()
{
    int arg1=534;
    int arg2=1057;
    int sum=swap_Add(&arg1,&arg2);
    int diff=arg1-arg2;

    return sum*diff;
}

int main()
{
    printf("%d\n",caller());
    return 0;
}