/**
 * 集合减法
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int findByIndex(vector<int> target, int val) {
    for (int i = 0; i < target.size(); ++i) {
        if (target[i] == val) return i;
    }

    return -1;
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<int> a;
        vector<int> b;
        vector<bool> visit(n, true);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }

        for (int i = 0; i < m; ++i) {
            int tmp;
            cin >> tmp;
            b.push_back(tmp);
        }

        for (int i = 0; i < m; ++i) {
            int index = findByIndex(a, b[i]);
            if (index != -1) {
                visit[index] = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (visit[i]) res.push_back(a[i]);
        }

        sort(res.begin(), res.end());

        if (res.empty()) cout << "NULL" << endl;
        else {
            for (int i = 0; i < res.size(); ++i) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}