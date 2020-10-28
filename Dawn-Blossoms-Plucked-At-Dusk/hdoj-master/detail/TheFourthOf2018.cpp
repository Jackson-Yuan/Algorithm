/**
 *瓜农王大爷去年种西瓜赚了不少钱。看到收入不错，今年他又重新开辟了n个西瓜地。 
 * 为了能给他的n个西瓜地顺利的浇上水，对于每个西瓜地他可以选择在本地打井，
 * 也可以修管道从另一个瓜地（这个瓜地可能打了井；也可能没打井，他的水也是从其他瓜地引来的）将水引过来。 
 * 当然打井和修管道的费用有差别。已知在第i个西瓜地打井需要耗费wi元，在第i、j个西瓜地之间修管道需要耗费pi,j元。 
 * 现在的问题是：王大爷要想使所有瓜地都被浇上水，至少需要花费多少钱（打井与修管道的费用和）？ 
 * 由于瓜地较多，王大爷无法选择在哪些（个）瓜地打井，哪些西瓜地之间修管道。 
 * 请你编程帮王大爷做出决策，求出最小费用。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct edge {
    int start;
    int end;
    int cost;
};
vector<int> root;

int findRoot(int start) {
    int res;
    int tmp = start;
    while (root[tmp] != -1) {
        tmp = root[tmp];
    }

    res = tmp;
    while (root[start] != -1) {
        tmp = root[start];
        root[start] = res;
        start = tmp;
    }

    return res;
}

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> link(n, vector<int>(n, 0));
    vector<int> baseCost(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> baseCost[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> link[i][j];
        }
    }

    vector<edge> edges;
    /**将已有的边先连上*/
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (link[i][j] != 0) {
                edge current;
                current.start = i;
                current.end = j;
                current.cost = link[i][j];
                edges.push_back(current);
            }
        }
    }

    /**井设为一个虚节点，编号为为n*/
    for (int i = 0; i < n; ++i) {
        edge current;
        current.start = n;
        current.end = i;
        current.cost = baseCost[i];
        edges.push_back(current);
    }

    root = vector<int>(n + 1, -1);
    sort(edges.begin(), edges.end(), cmp);
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < edges.size(); ++i) {
        int rootA = findRoot(edges[i].start);
        int rootB = findRoot(edges[i].end);
        if (rootA != rootB) {
            root[rootB] = rootA;
            res += edges[i].cost;
            ++cnt;
        }

        if (cnt == n) break;
    }

    cout << res << endl;
    return 0;
}
/**
 * 此题的核心就是将打井这个操作，设一个虚节点(起先本来是想搞n个节点，后来发现这么搞不符合题目要求)
 * 然后就直接转化成求最小生成树,这个设虚节点跟之前hdoj一个人的旅行十分类似
 * */