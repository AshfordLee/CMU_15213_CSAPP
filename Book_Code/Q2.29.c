#include <assert.h>
#define M 15
#define N 4
int arith(int x,int y)
{
    int result=0;
    result=x*M+y/N;
    return result;
}

int optarith(int x,int y)
{
    int t=x;
    x<<=4;
    x-=t;
    if (y<0)
    {
        y+=3;
    }
    y>>=2;
    return x+y;
}

int main()
{
    // 测试arith函数
    int x = 10, y = 20;
    int result1 = arith(x, y);
    int result2 = optarith(x, y);
    
    // 断言两个函数的结果应该相等
    assert(result1 == result2);
    
    // 断言x和y的值应该保持不变
    assert(x == 10);
    assert(y == 20);
    
    return 0;
}