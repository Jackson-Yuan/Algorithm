/**
 * 有n(n<=100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            res.push_back(tmp);
        }

        res.push_back(m);
        sort(res.begin(), res.end());
        for (int j = 0; j < res.size(); ++j) {
            cout << res[j];
            if (j != res.size() - 1) cout << " ";
        }

        cout << endl;
    }

    return 0;
}