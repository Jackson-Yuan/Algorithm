/**
 * n皇后问题
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;
bool graph[11][11];
bool visited[11];
int n;
int ans;

bool check(int x, int y) {
    int tmpX = x - 1, tmpY = y - 1;
    while (tmpX >= 0 && tmpY >= 0) {
        if (graph[tmpX][tmpY]) return false;
        --tmpX;
        --tmpY;
    }

    tmpX = x - 1, tmpY = y + 1;
    while (tmpX >= 0 && tmpY < n) {
        if (graph[tmpX][tmpY]) return false;
        --tmpX;
        ++tmpY;
    }
    return true;
}

void dfs(int index) {
    if (index == n) {
        ++ans;
        return;;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && check(index, i)) {
            visited[i] = true;
            graph[index][i] = true;
            dfs(index + 1);
            visited[i] = false;
            graph[index][i] = false;
        }
    }
}

int main() {
    map<int, int> m;
    while (true) {
        cin >> n;
        memset(visited, 0, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        if (n == 0) break;
        ans = 0;
        if (m.find(n) == m.end()) {
            dfs(0);
            m[n] = ans;
        } else {
            ans = m[n];
        }
        cout << ans << endl;
    }
    return 0;
}