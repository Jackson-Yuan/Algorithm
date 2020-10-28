/**
 * 算法笔记 p373
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <stdio.h>

using namespace std;

string intToStr(int val) {
    string res;
    while (val) {
        res.append(1, '0' + val % 10);
        val /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

struct link {
    string dest;
    double dis;
};
struct point {
    string name;
    vector<link> links;
};
string target;
double resDis, resAverage;
map<string, int> realIndex;

void digiKstra(vector<point> graph, string name, int n, int range) {
    int sum = graph.size(), start = realIndex[name];
    vector<double> minPath(sum, INT_MAX);
    vector<bool> visited(sum, false);
    minPath[start] = 0;
    int count = sum;
    while (count--) {
        int current = -1;
        double tmpMin = INT_MAX;
        for (int i = 0; i < sum; ++i) {
            if (!visited[i] && tmpMin > minPath[i]) {
                current = i;
                tmpMin = minPath[i];
            }
        }

        if (current == -1) break;
        visited[current] = true;
        vector<link> links = graph[current].links;
        double currentPath = minPath[current];
        for (int i = 0; i < links.size(); ++i) {
            int location = realIndex[links[i].dest];
            double dis = links[i].dis;
            if (!visited[location] && currentPath + dis < minPath[location]) {
                minPath[location] = currentPath + dis;
            }
        }
    }

    double res = INT_MAX, average = 0;
    bool token = true;
    for (int i = 0; i < n; ++i) {
        if (minPath[i] > range) {
            token = false;
            break;
        }
        if (minPath[i] < res) {
            res = minPath[i];
        }
        average += minPath[i];
    }

    if (token) {
        average /= n;
        if (res > resDis) {
            resDis = res;
            resAverage = average;
            target = name;
        } else if (res == resDis && average < resAverage) {
            resAverage = average;
            target = name;
        }
    }
}

int main() {
    int n, m, k, range;
    cin >> n >> m >> k >> range;
    vector<point> graph(n + m);
    for (int i = 0; i < n; ++i) {
        graph[i].name = intToStr(i + 1);
        realIndex[graph[i].name] = i;
    }
    for (int i = n; i < graph.size(); ++i) {
        graph[i].name = "G";
        graph[i].name = graph[i].name + intToStr(i - n + 1);
        realIndex[graph[i].name] = i;
    }

    for (int i = 0; i < k; ++i) {
        string start, end;
        int dis;
        cin >> start >> end >> dis;
        link current;
        current.dis = dis;
        current.dest = end;
        graph[realIndex[start]].links.push_back(current);
        current.dest = start;
        graph[realIndex[end]].links.push_back(current);
    }


    resDis = resAverage = -1;
    for (int i = 1; i <= k; ++i) {
        string name = "G";
        name += intToStr(i);
        digiKstra(graph, name, n, range);
    }

    if (resDis != -1) {
        cout << target << endl;
        printf("%.1lf %.1lf\n", resDis, resAverage);
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}