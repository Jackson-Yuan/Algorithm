#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;
int n, m, k;
int map[50][50];
int dp[50][50][15][15];

int dfs(int x, int y, int num, int max) {
    /**之所以max + 1 是防止物品价值为0 所用递归的开始 默认值为-1*/
    /**记忆化搜索体现之处  如果不等于-1  则证明之前这个状态已经搜索过 无需二次搜索*/
    if (dp[x][y][num][max + 1] != -1) return dp[x][y][num][max + 1];

    /**到达出口*/
    if (x == n && y == m) {
        if ((num == k) || (num == k - 1 && max < map[x][y])) {
            dp[x][y][num][max + 1] = 1;
            return dp[x][y][num][max + 1];
        } else {
            dp[x][y][num][max + 1] = 0;
            return dp[x][y][num][max + 1];
        }
    }

    long long s = 0;
    /**根据题目意思 一些简单的判断*/
    if (x + 1 <= n) {
        if (max < map[x][y]) s += dfs(x + 1, y, num + 1, map[x][y]);
        s += dfs(x + 1, y, num, max);
    }
    if (y + 1 <= m) {
        if (max < map[x][y]) s += dfs(x, y + 1, num + 1, map[x][y]);
        s += dfs(x, y + 1, num, max);
    }

    dp[x][y][num][max + 1] = s % 1000000007;
    return dp[x][y][num][max + 1];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    dfs(1, 1, 0, -1);
    printf("%d", dp[1][1][0][0]);
}

/**本题记忆化搜索 此题单纯的第一印象就是dfs遍历所有情况 来取值 但实际情况会超时 记忆化搜索 是搜索加动态规划的结合 把已经搜索过的状态保存起来 避免二次搜索*/
