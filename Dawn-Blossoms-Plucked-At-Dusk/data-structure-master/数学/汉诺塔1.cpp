#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;

long long pow(int a, int b) {//a^b
    long long base = a;
    long long ans = 1;
    base = base % 1000000;
    while (b != 0) {
        if (b & 1) {
            ans = (ans * base) % 1000000;
        }
        base = (base * base) % 1000000;
        b = b >> 1;
    }
    return ans;
}

long long changui(int a, int b) {
    long long ans = 1;
    long long temp = a % 1000000;
    for (int i = 0; i < b; i++) {
        ans = (ans * temp) % 1000000;
    }
    ans = ans % 1000000;
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int m;
        scanf("%d", &m);
        printf("%d\n", changui(2, m) - 1);
    }
}
/*
��������Ҫ���ÿ����ݵ��㷨 ����ʱ�临�Ӷȵ�
�������ģ����ļ����ȼ۹�ʽ
(a*b) mod c = (a mod c) * (b mod c) mod c 
����ȡ��λ�� ȡ��λ�� ����1�������λ����ͬλ����0 ȡģ 
*/
