/**
 * 省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。
 * 经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> root;

int findRoot(int start) {
    int res, tmp = start;
    while (root[start] != -1) {
        start = root[start];
    }
    res = start;
    while (root[tmp] != -1) {
        start = root[tmp];
        root[tmp] = res;
        tmp = start;
    }

    return res;
}

struct link {
    int start;
    int end;
    int cost;
};

bool cmp(link a, link b) {
    return a.cost < b.cost;
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0) break;
        root = vector<int>(m + 1, -1);
        vector<link> links;
        for (int i = 0; i < n; ++i) {
            link current;
            cin >> current.start >> current.end >> current.cost;
            links.push_back(current);
        }
        sort(links.begin(), links.end(), cmp);

        int res = 0;
        int count = 0;
        for (int i = 0; i < links.size(); ++i) {
            int a = links[i].start, b = links[i].end;
            int rootA = findRoot(a);
            int rootB = findRoot(b);

            if (rootA != rootB) {
                res += links[i].cost;
                root[rootB] = rootA;
                ++count;
            }

            if (count == m - 1) break;
        }

        if (count == m - 1) {
            cout << res << endl;
        } else cout << "?" << endl;
    }

    return 0;
}