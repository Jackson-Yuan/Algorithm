/**
 *算法笔记 p366
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct link {
    int dest;
    int distance;
    int cost;
};
struct point {
    vector<link> links;
};

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<point> graph(n);
    for (int i = 0; i < m; ++i) {
        int start, end, distance, cost;
        cin >> start >> end >> distance >> cost;
        link current;
        current.dest = end;
        current.distance = distance;
        current.cost = cost;
        graph[start].links.push_back(current);
        current.dest = start;
        graph[end].links.push_back(current);
    }

    vector<int> minPath(n, INT_MAX);
    vector<int> minCost(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> pre(n, -1);
    minPath[s] = 0;
    minCost[s] = 0;
    int count = n;
    while (count--) {
        int start = -1, tmpMin = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && tmpMin > minPath[i]) {
                tmpMin = minPath[i];
                start = i;
            }
        }

        if (start == -1) break;
        visited[start] = true;
        vector<link> links = graph[start].links;
        int currentPath = minPath[start];
        for (int i = 0; i < links.size(); ++i) {
            int location = links[i].dest, distance = links[i].distance, cost = links[i].cost;
            if (!visited[location]) {
                if (currentPath + distance < minPath[location]) {
                    minPath[location] = currentPath + distance;
                    minCost[location] = minCost[start] + cost;
                    pre[location] = start;
                } else if (currentPath + distance == minPath[location] && minCost[start] + cost < minCost[location]) {
                    minCost[location] = minCost[start] + cost;
                    pre[location] = start;
                }
            }
        }
    }

    vector<int> path;
    int start = d;
    while (pre[start] != -1) {
        path.push_back(start);
        start = pre[start];
    }
    path.push_back(start);

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }

    cout << minPath[d] << " " << minCost[d] << endl;
    return 0;
}
