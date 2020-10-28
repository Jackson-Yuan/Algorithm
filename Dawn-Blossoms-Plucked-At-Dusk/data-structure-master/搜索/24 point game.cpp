#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
double a[10];
int visited[10];
int flag;
int n;
int target;

void dfs(double s, int count) {
    if (flag == 1) return;
    if (count == n) {
        /*消除精度误差*/
        if (fabs(s - target) < 0.0000001) {
            flag = 1;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && flag == 0) {
            visited[i] = 1;
            dfs(s * a[i], count + 1);
            dfs(s + a[i], count + 1);
            dfs(a[i] - s, count + 1);
            dfs(s - a[i], count + 1);
            dfs(s / a[i], count + 1);
            dfs(a[i] / s, count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d", &n, &target);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            memset(visited, 0, sizeof(visited));
            visited[i] = 1;
            dfs(a[i], 1);
            if (flag == 1) break;
        }
        if (flag == 0) printf("No\n");
        else printf("Yes\n");
    }
}
/*
此题还是枚举 一般问你能不能达到某个目标 一般都用穷举 然后每个计算都把加减乘除都搜索一遍(减法和除法 要注意两者顺序 同时还要注意每个dfs函数中 循环一次 要将访问标记还原 以便于下个循环要访问的数能访问到还原的数)
劳资起先题目意思理解错了 以为要按输入顺序 插入加减乘除 扰乱劳资半天 草 
*/
