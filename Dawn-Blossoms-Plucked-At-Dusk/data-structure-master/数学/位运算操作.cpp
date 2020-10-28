#include<stdio.h>

int pow(int a, int b)//a^b
{
    int ans = 1;
    int base = a;
    while (b != 0) {
        if (b & 1 != 0) {//判断指数的二进制的当前为是否为1
            ans *= base;
        }
        base *= base;
        b = b >> 1;//向左移 一旦二进制表达式移完 为0
    }
    return ans;
}

/*这个方法 其实是降低时间复杂度 因为直接暴力算a^b 要把a算b次 线性级别  此种方法为降到了对数级*/
int main() {
    /*int a = 1;
    int b= 2;
    a = a<<1;
    b = b>>1;
    printf("%d\n",a);
    printf("%d\n",b&1);*/
    printf("%d", pow(2, 10));
}
