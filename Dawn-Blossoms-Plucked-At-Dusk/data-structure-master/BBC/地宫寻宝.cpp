#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;
int n, m, k;
int map[50][50];
int dp[50][50][15][15];

int dfs(int x, int y, int num, int max) {
    /**֮����max + 1 �Ƿ�ֹ��Ʒ��ֵΪ0 ���õݹ�Ŀ�ʼ Ĭ��ֵΪ-1*/
    /**���仯��������֮��  ���������-1  ��֤��֮ǰ���״̬�Ѿ������� �����������*/
    if (dp[x][y][num][max + 1] != -1) return dp[x][y][num][max + 1];

    /**�������*/
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
    /**������Ŀ��˼ һЩ�򵥵��ж�*/
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

/**������仯���� ���ⵥ���ĵ�һӡ�����dfs����������� ��ȡֵ ��ʵ������ᳬʱ ���仯���� �������Ӷ�̬�滮�Ľ�� ���Ѿ���������״̬�������� �����������*/
