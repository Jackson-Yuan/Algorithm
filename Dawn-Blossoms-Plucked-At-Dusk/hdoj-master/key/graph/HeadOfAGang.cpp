/**
 * 算法笔记 p348
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct link {
    string des;
    int cost;
};
struct point {
    string name;
    vector<link> links;
};
struct resNode {
    string name;
    int size;
};
vector<point> graph;
vector<bool> visited;
map<string, bool> isEnter;
map<string, int> realIndex;
vector<string> gang;
int countValue;

void dfs(int start) {
    visited[start] = true;
    gang.push_back(graph[start].name);
    vector<link> links = graph[start].links;
    for (int i = 0; i < links.size(); ++i) {
        countValue += links[i].cost;
        if (!visited[realIndex[links[i].des]]) {
            dfs(realIndex[links[i].des]);
        }
    }
}

bool cmp(resNode a, resNode b) {
    return a.name < b.name;
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        graph.clear();
        isEnter.clear();
        realIndex.clear();
        vector<int> degree;
        int index = 0;
        for (int i = 0; i < n; ++i) {
            string start, end;
            int cost;
            cin >> start >> end >> cost;
            if (!isEnter[start]) {
                isEnter[start] = true;
                realIndex[start] = index;
                ++index;
                point current;
                current.name = start;
                graph.push_back(current);
                degree.push_back(0);
            }

            if (!isEnter[end]) {
                isEnter[end] = true;
                realIndex[end] = index;
                ++index;
                point current;
                current.name = end;
                graph.push_back(current);
                degree.push_back(0);
            }

            link current;
            current.des = end;
            current.cost = cost;
            graph[realIndex[start]].links.push_back(current);
            degree[realIndex[start]] += current.cost;
            degree[realIndex[end]] += current.cost;
        }

        vector<vector<string>> gangs;
        visited = vector<bool>(graph.size(), false);
        for (int i = 0; i < graph.size(); ++i) {
            if (!visited[i]) {
                countValue = 0;
                gang.clear();
                dfs(i);
                if (countValue > k && gang.size() > 2) {
                    gangs.push_back(gang);
                }
            }
        }

        cout << gangs.size() << endl;
        vector<resNode> res;
        for (int i = 0; i < gangs.size(); ++i) {
            string maxName = gangs[i][0];
            int maxValue = degree[realIndex[maxName]];
            for (int j = 1; j < gangs[i].size(); ++j) {
                if (degree[realIndex[gangs[i][j]]] > maxValue) {
                    maxName = gangs[i][j];
                    maxValue = degree[realIndex[gangs[i][j]]];
                }
            }

            resNode current;
            current.name = maxName;
            current.size = gangs[i].size();
            res.push_back(current);
        }

        sort(res.begin(), res.end(), cmp);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].name << " " << res[i].size << endl;
        }
    }

    return 0;
}