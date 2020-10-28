#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int n;
bool map[1001][1001];
bool visited[1001];

void dfs(int location) {
    if (visited[location] == 1) return;
    visited[location] = 1;
    for (int i = 1; i <= n; i++) {
        if (map[location][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }

}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int r;
        scanf("%d %d", &n, &r);
        memset(map, 0, (n + 1) * (n + 1) * sizeof(bool));
        memset(visited, 0, (n + 1) * sizeof(bool));
        int sum = 0;
        for (int i = 0; i < r; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            map[a][b] = 1;
            map[b][a] = 1;
        }
        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (int j = 1; j <= n; j++) {
                if (j != i && map[i][j] == 1) {
                    count++;
                }
            }
            if (count % 2 != 0) {
                sum++;
            }
        }
        int flag = 1;
        dfs(1);
        for (int i = 1; i <= n; i++) {
            if (visited[i] != 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && (sum == 2 || sum == 0)) printf("Yes\n");
        else printf("No\n");
    }

}
/*
欧拉回路问题 
利用dfs统计每个点是否被访问到
然后统计度数为奇数的点的个数是否为2或0
就可以判断是否能一笔画了 

*/
