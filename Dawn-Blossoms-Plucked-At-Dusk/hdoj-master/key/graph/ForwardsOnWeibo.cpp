/**
 * 算法笔记 p354
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int res;
struct point {
    int val;
    int step;
};

void bfs(int start, int end) {
    queue<point> q;
    point initial;
    initial.val = start;
    initial.step = 0;
    q.push(initial);
    visited[initial.val] = true;
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        if (current.step > end) break;
        if (current.step != 0 && current.step <= end) ++res;
        for (int i = 0; i < graph[current.val].size(); ++i) {
            if (!visited[graph[current.val][i]]) {
                visited[graph[current.val][i]] = true;
                point next;
                next.val = graph[current.val][i];
                next.step = current.step + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, l;
    while (cin >> n >> l) {
        graph = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 1; i <= n; ++i) {
            int sum;
            cin >> sum;
            for (int j = 0; j < sum; ++j) {
                int follow;
                cin >> follow;
                graph[follow].push_back(i);
            }
        }

        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int start;
            cin >> start;
            res = 0;
            visited = vector<bool>(n + 1, false);
            bfs(start, l);
            cout << res << endl;
        }
    }
    return 0;
}