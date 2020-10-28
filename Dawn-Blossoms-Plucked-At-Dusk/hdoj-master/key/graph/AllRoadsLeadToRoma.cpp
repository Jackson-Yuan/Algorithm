/**
 * 算法笔记 p377
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
    string dest;
    int cost;
};
struct point {
    string name;
    int happiness;
    vector<link> links;
};
string start;
vector<string> resPath, tmpPath;
int resCount, resCost, resHappiness, resAverageHappiness;
vector<point> graph;
vector<bool> visited;
map<string, int> realIndex;
vector<vector<string>> prePath;

void dfs(int index) {
    if (graph[index].name == start) {
        ++resCount;
        tmpPath.push_back(graph[index].name);
        int tmpHappiness = 0;
        for (int i = 0; i < tmpPath.size() - 1; ++i) {
            tmpHappiness += graph[realIndex[tmpPath[i]]].happiness;
        }
        int tmpAverage = tmpHappiness / (tmpPath.size() - 1);
        if (tmpHappiness > resHappiness) {
            resHappiness = tmpHappiness;
            resAverageHappiness = tmpAverage;
            resPath = tmpPath;
        } else if (tmpHappiness == resHappiness && tmpAverage > resAverageHappiness) {
            resAverageHappiness = tmpAverage;
            resPath = tmpPath;
        }
        tmpPath.pop_back();
        return;;
    }

    tmpPath.push_back(graph[index].name);
    for (int i = 0; i < prePath[index].size(); ++i) {
        int next = realIndex[prePath[index][i]];
        dfs(next);
    }
    tmpPath.pop_back();
}

int main() {
    int n, k;
    cin >> n >> k >> start;
    graph = vector<point>(n);
    graph[0].name = start;
    realIndex[start] = 0;

    for (int i = 1; i < n; ++i) {
        string name;
        int happiness;
        cin >> name >> happiness;
        graph[i].name = name;
        graph[i].happiness = happiness;
        realIndex[name] = i;
    }

    for (int i = 0; i < k; ++i) {
        string a, b;
        int cost;
        cin >> a >> b >> cost;
        link current;
        current.cost = cost;
        current.dest = b;
        graph[realIndex[a]].links.push_back(current);
        current.dest = a;
        graph[realIndex[b]].links.push_back(current);
    }

    vector<int> minPath(n, INT_MAX);
    visited = vector<bool>(n, false);
    prePath = vector<vector<string>>(n);
    minPath[realIndex[start]] = 0;
    int count = n;
    while (count--) {
        int current = -1, tmpMin = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && tmpMin > minPath[i]) {
                tmpMin = minPath[i];
                current = i;
            }
        }

        if (current == -1) break;
        visited[current] = true;
        int currentPath = minPath[current];
        vector<link> links = graph[current].links;
        for (int i = 0; i < links.size(); ++i) {
            int location = realIndex[links[i].dest];
            int cost = links[i].cost;
            if (!visited[location]) {
                if (currentPath + cost < minPath[location]) {
                    minPath[location] = currentPath + cost;
                    prePath[location].clear();
                    prePath[location].push_back(graph[current].name);
                } else if (currentPath + cost == minPath[location]) {
                    prePath[location].push_back(graph[current].name);
                }
            }
        }
    }

    resCost = minPath[realIndex["ROM"]];
    resCount = 0;
    resAverageHappiness = -1;
    resHappiness = -1;
    dfs(realIndex["ROM"]);
    cout << resCount << " " << resCost << " " << resHappiness << " " << resAverageHappiness << endl;
    for (int i = resPath.size() - 1; i >= 0; --i) {
        cout << resPath[i];
        if (i != 0) cout << "->";
        else cout << endl;
    }

    return 0;
}