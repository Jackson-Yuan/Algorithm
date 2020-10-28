/**
 * 算法笔记 p338
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
bool visited[1001];
vector<vector<int>> graph;

void dfs(int start) {
    visited[start] = true;
    for (int i = 0; i < graph[start].size(); ++i) {
        if (!visited[graph[start][i]]) {
            dfs(graph[start][i]);
        }
    }
}

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        graph = vector<vector<int>>(n);
        for (int i = 0; i < m; ++i) {
            int start, end;
            cin >> start >> end;
            graph[start - 1].push_back(end - 1);
            graph[end - 1].push_back(start - 1);
        }

        for (int i = 0; i < k; ++i) {
            memset(visited, 0, sizeof(visited));
            int target;
            cin >> target;
            visited[target - 1] = true;
            int res = 0;
            for (int j = 0; j < n; ++j) {
                if (j != (target - 1) && !visited[j]) {
                    ++res;
                    dfs(j);
                }
            }

            cout << res - 1 << endl;
        }
    }
    return 0;
}
/**
 * 利用dfs或并查集寻找连通块数
 * 所需的高速公路就为连通块数减一
 * 关于题目要求中删去点及连的边，没有必要真删除，直接标记为已经访问即可
 * */