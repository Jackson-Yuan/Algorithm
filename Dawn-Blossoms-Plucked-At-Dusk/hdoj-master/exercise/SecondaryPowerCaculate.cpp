/**
 * 求A^B的最后三位数表示的整数。
 * 说明：A^B的含义是“A的B次方”
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
        int res = 1;
        for (int i = 0; i < m; ++i) {
            res *= n;
            res = res % 1000;
        }

        cout << res << endl;
    }

    return 0;
}