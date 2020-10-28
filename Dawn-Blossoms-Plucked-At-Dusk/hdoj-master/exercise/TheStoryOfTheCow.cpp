/**
 * 有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
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
        for (int i = 0; i < 4; ++i) {
            res.push_back(i + 1);
        }

        for (int j = 4; j < n; ++j) {
            int tmp = res[j - 1] + res[j - 3];
            res.push_back(tmp);
        }

        cout << res[n - 1] << endl;
    }

    return 0;
}