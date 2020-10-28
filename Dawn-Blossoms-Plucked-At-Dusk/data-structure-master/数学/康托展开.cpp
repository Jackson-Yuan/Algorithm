/**
����
һ����������n,k
���ݹ�ģ(n<=20,k<=n!)
���
ǰn��Сд��ĸȫ���еĵ�k��
*/
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
int visited[26];

long long fact(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    memset(visited, 0, sizeof(visited));


    k--;
    long long temp = n;
    n--;
    while (n != 0) {
        long long sum = k / fact(n);
        long long count = 0;
        for (long long i = 0; i < temp; i++) {
            if (count == sum && visited[i] == 0) {
                printf("%c", i + 97);
                visited[i] = 1;
                break;
            }
            if (visited[i] == 0) count++;
        }
        k = k % fact(n);
        n--;
    }
    for (long long i = 0; i < temp; i++) {
        if (visited[i] == 0) {
            printf("%c", i + 97);
            break;
        }
    }
    printf("\n");
}
/*
һ��ȫ���е�һ����Ȼ����ӳ��(һһ��Ӧ��ϵ)
x = an*(n-1)! + an-1*(n-2)! + ...... + a1*0!
ûɶ�Ƶ� ���Ǹ����� ����������ɵ���Ҳ��ͦ����
ai��ʾԭ���ĵ�iλ�ڵ�ǰΪ����Ԫ�������ڵڼ���(��0��ʼ) 
������ n = 5 x = 65
���������65��ȫ�����Ǹ�ɶ��  ���ʱ����Ҫ��x--
��Ȼ������һһӳ���ϵ �������������� Ҳ������������ŵڼ���
�㷨����
��n=5,x=96ʱ��
������96-1�õ�95��˵��x֮ǰ��95������.(�����������ȥ1)
��95ȥ��4! �õ�3��23��˵����3�����ȵ�1λС��
���Ե�һλ��4.��23ȥ��3! �õ�3��5��˵����3�����ȵ�2λС��������4������4�ѳ��ֹ��������5.
��5ȥ��2!�õ�2��1�����Ƶأ���һλ��3.
��1ȥ��1!�õ�1��0����һλ��2.
���һλֻ����1.�����������45321��   
**/ 
