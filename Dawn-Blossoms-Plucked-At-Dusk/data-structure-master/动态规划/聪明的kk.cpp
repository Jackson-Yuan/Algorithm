#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int map[21][501];

int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int a = -1;
            int b = -1;
            if (i - 1 >= 0 && map[i][j] + map[i - 1][j] > map[i][j]) {
                a = map[i][j] + map[i - 1][j];
            }

            if (j - 1 >= 0 && map[i][j] + map[i][j - 1] > map[i][j]) {
                b = map[i][j] + map[i][j - 1];
            }
            if (a > b) map[i][j] = a;
            else map[i][j] = b;
        }
    }

    printf("%d\n", map[n - 1][m - 1]);
}
/*
此题为动态规划 原理就是 因为只能向下或向右走 所以动态规划时
确保二维数组每个索引的值都为小虫吃到这个位置的最大值
所以确定好动态规划数组的遍历顺序
依次遍历判断 当前位置 是从向上来的大 还是从向左来的大
最后打印出结果即可 
*/
