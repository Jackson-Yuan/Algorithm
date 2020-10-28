#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stdio.h>

using namespace std;

int main() {
    int a[41];
    int N;
    scanf("%d", &N);
    while (N--) {
        memset(a, 0, sizeof(a));
        a[1] = 0;
        a[2] = 1;
        int m;
        scanf("%d", &m);
        if (m <= 2) {
            printf("%d\n", a[m]);
            continue;
        }
        a[1] = 1;
        for (int i = 3; i <= m; i++) {
            a[i] = a[i - 2] + a[i - 1];
        }
        printf("%d\n", a[m]);
    }
}
/*
动态规划
每打一级的次数 等于到她前一级的次数与前两级的次数之和
但要注意 根据题目意思 他开始的时候是站在第一台阶上的
所以边界值要注意(最优子结构 转移方程 边界) 
*/ 
