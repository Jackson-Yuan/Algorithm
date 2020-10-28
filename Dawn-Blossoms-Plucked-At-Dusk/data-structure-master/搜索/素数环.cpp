#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;

int visited[21];
int n;
int result[21];
int flag;
int prime[40] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
                 0, 0, 0, 1, 0, 0};

void dfs(int x, int index) {
    if (visited[x] == 1) return;
    if (prime[result[index] + x]) {
        index++;
        result[index] = x;
    } else {
        return;
    }
    if (index == n) {
        if (prime[result[n] + result[1]]) {
            flag = 1;
            for (int i = 1; i <= n; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
        return;
    }
    /*标记的访问与还原 可以放在循环内
    也可以放在循环内
    只要保证退出这个函数时 将标记点还原就行
    */
    visited[x] = 1;
    for (int i = 1; i <= n; i++) {
        /*visited[x] = 1;*/
        if (visited[i] == 0) {
            dfs(i, index);
        }
        /*visited[x] = 0;*/
    }
    visited[x] = 0;
}

int main() {
    int sum = 0;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        sum++;
        if (n % 2 != 0 && n != 1) {
            printf("Case %d:\n", sum);
            printf("No Answer\n");
            continue;
        }
        memset(visited, 0, sizeof(visited));
        result[0] = 0;
        flag = 0;
        printf("Case %d:\n", sum);
        dfs(1, 0);
        if (flag == 0) printf("No Answer\n");
    }
}
/*
本题第一步 先将数据想像成1-n 都连接的连通图组织起来，通过标记访问与还原访问标记，来达到实现多种dfs路径的功能
在dfs过程中国 没过一个点判断是否与前一个点合为素数 ，然后压入结果数组，当能凑齐n个的时候，再判断是否首尾为素数，能打印，
不能的话 结束 回溯到上一步继续试探
同时 要注意 n为奇数且n不为1的时候不可能有 要特别指出，否则超时 
*/
