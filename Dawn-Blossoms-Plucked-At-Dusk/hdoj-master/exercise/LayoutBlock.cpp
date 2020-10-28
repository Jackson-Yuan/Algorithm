/**
 * 在2×n的一个长方形方格中,用一个1× 2的骨牌铺满方格,输入n ,输出铺放方案的总数.
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
    while (cin >> n) {
        vector<long long> res;
        res.push_back(1);
        res.push_back(2);
        res.push_back(3);
        for (int i = 3; i < n; ++i) {
            long long tmp = res[i - 1] + res[i - 2];
            res.push_back(tmp);
        }

        cout << res[n - 1] << endl;
    }

    return 0;
}