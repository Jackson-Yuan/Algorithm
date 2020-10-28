/**
输入
一行两个整数n,k
数据规模(n<=20,k<=n!)
输出
前n个小写字母全排列的第k个
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
一个全排列到一个自然数的映射(一一对应关系)
x = an*(n-1)! + an-1*(n-2)! + ...... + a1*0!
没啥推导 就是个规律 发现这个规律的人也是挺吊的
ai表示原数的第i位在当前为出现元素中排在第几个(从0开始) 
给出你 n = 5 x = 65
可以求出第65个全排列是个啥样  算的时候先要将x--
当然由于是一一映射关系 反过来给定序列 也可以算出这是排第几个
算法过程
如n=5,x=96时：
首先用96-1得到95，说明x之前有95个排列.(将此数本身减去1)
用95去除4! 得到3余23，说明有3个数比第1位小，
所以第一位是4.用23去除3! 得到3余5，说明有3个数比第2位小，所以是4，但是4已出现过，因此是5.
用5去除2!得到2余1，类似地，这一位是3.
用1去除1!得到1余0，这一位是2.
最后一位只能是1.所以这个数是45321。   
**/ 
