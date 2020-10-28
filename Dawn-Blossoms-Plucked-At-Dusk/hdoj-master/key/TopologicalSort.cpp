/**
 * 图论中的拓扑排序，核心在于开个数组统计入度大小
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct link {
    int destination;
};
struct point {
    int val;
    vector<link> links;
};

int main() {
    map<int, bool> isEnter;
    map<int, int> realIndex;
    vector<point> graph;
    int index = 0;
    vector<int> inDegree;
    for (int i = 0; i < 5; ++i) {
        int start, end;
        cin >> start >> end;
        if (!isEnter[start]) {
            isEnter[start] = true;
            point tmp;
            tmp.val = start;
            graph.push_back(tmp);
            realIndex[start] = index;
            inDegree.push_back(0);
            ++index;
        }

        if (!isEnter[end]) {
            isEnter[end] = true;
            point tmp;
            tmp.val = end;
            graph.push_back(tmp);
            realIndex[end] = index;
            inDegree.push_back(0);
            ++index;
        }

        link currentLink;
        currentLink.destination = end;
        graph[realIndex[start]].links.push_back(currentLink);
        ++inDegree[realIndex[end]];
    }

    queue<int> q;/**用队列或栈保存可选的入读为0的点*/
    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int start = q.front();
        q.pop();
        cout << graph[start].val << " ";
        vector<link> links = graph[start].links;
        for (int i = 0; i < links.size(); ++i) {
            --inDegree[realIndex[links[i].destination]];
            if (inDegree[realIndex[links[i].destination]] == 0) {
                q.push(realIndex[links[i].destination]);
            }
        }
    }

    return 0;
}