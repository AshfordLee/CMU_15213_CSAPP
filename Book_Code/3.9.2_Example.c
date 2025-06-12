#include<stdio.h>

double bit2double(unsigned word0,unsigned word1)
{
    union{
        double d;
        unsigned u[2];
    }temp;

    temp.u[0]=word0;
    temp.u[1]=word1;
    return temp.d;
}

int main()
{
    unsigned word0=0x5f3759df;
    unsigned word1=0x00000000;
    double result=bit2double(word0,word1);
    printf("The double value is: %f\n",result);
    return 0;
}