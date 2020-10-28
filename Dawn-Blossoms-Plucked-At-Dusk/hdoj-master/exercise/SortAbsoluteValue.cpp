/**
 * 输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<int> res;
        map<int, int> m;

        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (tmp < 0) {
                tmp = -tmp;
                m[tmp] = 1;
            }
            res.push_back(tmp);
        }


        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());

        for (int j = 0; j < res.size(); ++j) {
            if (m[res[j]] == 1) {
                res[j] = -res[j];
            }

            cout << res[j];
            if (j != res.size() - 1) cout << " ";
        }

        cout << endl;
    }

    return 0;
}