/**
 * 求n个数的最小公倍数。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

long long getMax(long long a, long long b) {
    if (a > b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }

    long long sum = a * b;

    while (a) {
        long long tmp = a;
        a = b % a;
        b = tmp;
    }

    return sum / b;
}

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            res.push_back(tmp);
        }

        if (res.size() == 1) {
            cout << res[0] << endl;
            continue;
        }

        long long val = getMax(res[0], res[1]);
        for (int j = 2; j < res.size(); ++j) {
            val = getMax(val, res[j]);
        }

        cout << val << endl;
    }
    return 0;
}
/**
 * 此题是求n个数的公倍数，最初的做法是将前n-1个数的积与最后一个数求公倍数，但这个转化并不等价，只能逐个求公倍数
 * */