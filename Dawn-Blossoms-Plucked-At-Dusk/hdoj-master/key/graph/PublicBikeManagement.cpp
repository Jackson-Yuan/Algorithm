/**
 * 算法笔记 p361
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
struct link {
    int dest;
    int cost;
};
struct point {
    int number;
    vector<link> links;
};
vector<point> graph;
vector<bool> visited;
vector<vector<int>> realPath;
vector<int> curPath;
vector<vector<int>> concretePath;

void dfs(int current) {
    if (current == 0) {
        curPath.push_back(current);
        realPath.push_back(curPath);
        curPath.pop_back();
        return;
    }

    curPath.push_back(current);
    for (int i = 0; i < concretePath[current].size(); ++i) {
        if (!visited[concretePath[current][i]]) {
            visited[concretePath[current][i]] = true;
            dfs(concretePath[current][i]);
            visited[concretePath[current][i]] = false;
        }
    }
    curPath.pop_back();
}

int main() {
    int c, n, target, m;
    cin >> c >> n >> target >> m;
    graph = vector<point>(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> graph[i].number;
    }

    for (int i = 0; i < m; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        link current;
        current.dest = end;
        current.cost = cost;
        graph[start].links.push_back(current);
        current.dest = start;
        graph[end].links.push_back(current);
    }

    vector<int> minPath(n + 1, INT_MAX);
    visited = vector<bool>(n + 1, false);
    concretePath = vector<vector<int>>(n + 1);/**用来记录最短路径的前驱而非具体的路径，如果记录具体路径，得开三维数组*/
    minPath[0] = 0;
    int count = n + 1;
    while (count--) {
        int start = -1, tmpMin = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            if (!visited[i] && tmpMin > minPath[i]) {
                start = i;
                tmpMin = minPath[i];
            }
        }

        if (start == -1) break;
        visited[start] = true;
        vector<link> links = graph[start].links;
        int currentPath = minPath[start];
        for (int i = 0; i < links.size(); ++i) {
            int location = links[i].dest;
            int cost = links[i].cost;
            if (!visited[location]) {
                if (currentPath + cost < minPath[location]) {
                    minPath[location] = currentPath + cost;
                    concretePath[location].clear();
                    concretePath[location].push_back(start);
                } else if (currentPath + cost == minPath[location]) {
                    concretePath[location].push_back(start);
                }
            }
        }
    }

    visited = vector<bool>(n + 1, false);
    dfs(target);
    int resNeed = INT_MAX, resRemain = INT_MAX;
    vector<int> res;
    for (int i = 0; i < realPath.size(); ++i) {
        vector<int> path = realPath[i];
        vector<int> need(n + 1, 0);
        vector<int> remain(n + 1, 0);
        for (int j = path.size() - 2; j >= 0; --j) {
            int location = path[j], pre = path[j + 1];
            int number = graph[location].number;
            if (number >= c / 2) {
                remain[location] = remain[pre] + number - c / 2;
                need[location] = need[pre];
            } else {
                int dif = c / 2 - number;
                if (remain[pre] >= dif) {
                    remain[location] = remain[pre] - dif;
                    need[location] = need[pre];
                } else {
                    remain[location] = 0;
                    need[location] = need[pre] + (dif - remain[pre]);
                }
            }
        }
        if (need[target] < resNeed) {
            resNeed = need[target];
            resRemain = remain[target];
            res = path;
        } else if (need[target] == resNeed && remain[target] < resRemain) {
            resRemain = remain[target];
            res = path;
        }
    }

    cout << resNeed << " ";
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
        if (i != 0) cout << "->";
        else cout << " ";
    }
    cout << resRemain << endl;


    return 0;
}
/**
 * 此题依然玩花样，本想把需要值与带回值在迪杰斯特拉迭代里面算出来，结果不是正确的思路（但测试样例只错了一个）
 * 只能先将两个点所有最短路径保存下来，再一一比较
 * 这也给我们提供了一个应对迪杰斯特拉加玩点花样的通用解法
 * 先算出所有最短路径的轨迹(因为这种题目，肯定是最短路径为第一判别条件)，再对加的花样判别
 * 对于如何求两个所有点所有的路径，不是开三维数组保存
 * 而是只保存前驱，然后利用dfs暴力出所有路径
 * */