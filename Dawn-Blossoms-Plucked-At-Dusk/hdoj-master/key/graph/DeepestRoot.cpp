/**
 * 算法笔记 p343
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> root;
vector<bool> visited;
vector<vector<int>> graph;

int find(int start) {
    int tmp = start;
    int res;
    while (root[tmp] != -1) tmp = root[tmp];
    res = tmp;

    while (root[start] != -1) {
        tmp = root[start];
        root[start] = res;
        start = tmp;
    }

    return res;
}

void dfs(int start, int count, int &maxValue) {
    if (count > maxValue) maxValue = count;
    visited[start] = true;

    for (int i = 0; i < graph[start].size(); ++i) {
        if (!visited[graph[start][i]]) {
            dfs(graph[start][i], count + 1, maxValue);
        }
    }

    visited[start] = false;
}

int main() {
    int n;
    while (cin >> n) {
        root = vector<int>(n, -1);
        graph = vector<vector<int>>(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            int start, end;
            cin >> start >> end;
            graph[start - 1].push_back(end - 1);
            graph[end - 1].push_back(start - 1);
            int startRoot = find(start - 1);
            int endRoot = find(end - 1);
            if (startRoot != endRoot) {
                root[endRoot] = startRoot;
            }
        }
        int count = 0;
        for (int i = 0; i < root.size(); ++i) {
            if (root[i] == -1) ++count;
        }

        if (count != 1) {
            cout << "Error: " << count << " components" << endl;
            continue;
        }

        vector<int> maxPath(n, 0);
        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            visited = vector<bool>(n, false);
            int count = 0;
            dfs(i, 0, count);
            maxPath[i] = count;
            if (count > maxValue) maxValue = count;
        }

        for (int i = 0; i < maxPath.size(); ++i) {
            if (maxPath[i] == maxValue) cout << i + 1 << endl;
        }

    }

    return 0;
}
/**
 * 此题大意就是给n个点,n - 1条边,寻找一颗树(可能是一颗树得判断)中从某个节点开始深度最大的节点，有多个按顺序打印
 * 首先判断额是树，因为树是不可能有环的，起先认为并查集无法判断，但由于题目条件的特殊，n个点，n - 1条边
 * 使得并查集判断成为可能，因为这个条件想要成为树，必须所有点连通
 *
 * 剩余的比大小，直接每个点dfs暴力直接完事
 * */