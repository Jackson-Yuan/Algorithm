#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
int a[100];
int result[100];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(result, 0, sizeof(result));
    result[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (result[i - 1] < 0) {
            result[i] = a[i];
        } else {
            result[i] = result[i - 1] + a[i];
        }
    }

    int max = result[0];
    for (int i = 0; i < n; i++) {
        if (max < result[i]) max = result[i];
    }

    printf("%d\n", max);
}
/*
超级经典的动态规划 
最大连续子串和
result[i]代表以a[i]为连续子串和终点的情况下的最大值
全部遍历一遍
然后再从以每个a[i]为连续子串和的终点的所有情况中寻找最大值hhh
*/ 
