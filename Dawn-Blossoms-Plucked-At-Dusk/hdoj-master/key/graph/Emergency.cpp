/**
 * 算法笔记 p357
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
    int destination;
    int cost;
};
struct point {
    int number;
    vector<link> links;
};

int main() {
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<point> graph(n);
    for (int i = 0; i < n; ++i) {
        cin >> graph[i].number;
    }

    for (int i = 0; i < m; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        link current;
        current.destination = end;
        current.cost = cost;
        graph[start].links.push_back(current);
        current.destination = start;
        graph[end].links.push_back(current);
    }

    vector<int> minPath(n, INT_MAX);
    vector<int> maxNumber(n, 0);
    vector<bool> visited(n, false);
    vector<int> countPath(n, 0);
    minPath[c1] = 0;
    maxNumber[c1] = graph[c1].number;
    countPath[c1] = 1;
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
        int currentPath = minPath[start];
        int currentNumber = maxNumber[start];
        vector<link> links = graph[start].links;
        for (int i = 0; i < links.size(); ++i) {
            int location = links[i].destination;
            int cost = links[i].cost;
            int number = graph[location].number;
            if (!visited[location]) {
                if (currentPath + cost < minPath[location]) {
                    minPath[location] = currentPath + cost;
                    maxNumber[location] = currentNumber + number;
                    /**countPath[location] = 1*/
                    countPath[location] = countPath[start];/** 算最短路径有多少条不能直接设1，因为可能start这个点自身不止一条道路满足start点的最短路径*/
                } else if (currentPath + cost == minPath[location]) {
                    if (currentNumber + number > maxNumber[location]) maxNumber[location] = currentNumber + number;
                    /**++countPath[location]*/
                    countPath[location] += countPath[start];/** 与上面同理*/
                }
            }
        }
    }

    cout << countPath[c2] << " " << maxNumber[c2] << endl;


    return 0;
}