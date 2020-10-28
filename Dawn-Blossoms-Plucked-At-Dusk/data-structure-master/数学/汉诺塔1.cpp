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
此题首先要晓得快速幂的算法 降低时间复杂度的
其二掌握模运算的几个等价公式
(a*b) mod c = (a mod c) * (b mod c) mod c 
还有取几位数 取几位数 就与1后面跟几位数相同位数的0 取模 
*/
