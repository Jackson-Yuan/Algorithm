#include<stdio.h>

int pow(int a, int b)//a^b
{
    int ans = 1;
    int base = a;
    while (b != 0) {
        if (b & 1 != 0) {//�ж�ָ���Ķ����Ƶĵ�ǰΪ�Ƿ�Ϊ1
            ans *= base;
        }
        base *= base;
        b = b >> 1;//������ һ�������Ʊ��ʽ���� Ϊ0
    }
    return ans;
}

/*������� ��ʵ�ǽ���ʱ�临�Ӷ� ��Ϊֱ�ӱ�����a^b Ҫ��a��b�� ���Լ���  ���ַ���Ϊ�����˶�����*/
int main() {
    /*int a = 1;
    int b= 2;
    a = a<<1;
    b = b>>1;
    printf("%d\n",a);
    printf("%d\n",b&1);*/
    printf("%d", pow(2, 10));
}
