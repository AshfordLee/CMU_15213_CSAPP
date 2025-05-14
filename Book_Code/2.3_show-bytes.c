#include<stdio.h>
#include <string.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start,int len)
{
    int i;
    for(i=0;i<len;i++)
    {

        printf("%.2x",start[i]);
        printf("\n");
    }
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void* x)
{
    show_bytes((byte_pointer) &x,sizeof(void*));
}

int main()
{
    int a = 15213;
    float b = 15213.0;
    int* c = &a;
    
    printf("int a = 15213:\n");
    show_int(a);
    
    printf("float b = 15213.0:\n");
    show_float(b);
    
    printf("int* c = &a:\n");
    show_pointer(c);
    
    int val=0x12345678;
    byte_pointer valp=(byte_pointer) &val;
    printf("int val=0x12345678:\n");
    show_bytes(valp,1);
    printf("next,step=2\n");
    show_bytes(valp,2);
    printf("next,step=3\n");
    show_bytes(valp,3);

    const char* s="ABCDEF";
    printf("char *s=\"ABCDEF\";\n");
    show_bytes((byte_pointer)s,strlen(s));
    return 0;
}
    