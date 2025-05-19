#include<stdio.h>

float sum_elements(float a[],unsigned length)
{
    int i;
    float result=0;

    for (i=0;i<=length-1;i++)
    {
        result+=a[i];
    }

    return result;
}
// 有bug的错误，因为length下溢了


void main()
{
    float a[]={1.0,2.0,3.0,4.0,5.0};
    unsigned length=0;
    printf("sum_elements(a,length) = %f\n",sum_elements(a,length));
}