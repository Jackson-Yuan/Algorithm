/**
 * 把一个偶数拆成两个不同素数的和，有几种拆法呢？
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
        vector<bool> notPrime(n + 1, false);
        vector<int> prime;

        for (int i = 2; i < notPrime.size(); ++i) {
            if (notPrime[i]) continue;
            prime.push_back(i);
            int val = 2;
            while (i * val < notPrime.size()) {
                notPrime[i * val] = true;
                ++val;
            }
        }

        int count = 0;
        int start = 0, end = prime.size() - 1;
        while (start < end) {
            int tmp = prime[start] + prime[end];
            if (tmp > n) {
                --end;
            } else if (tmp < n) {
                ++start;
            } else {
                ++count;
                ++start;
                --end;
            }
        }

        cout << count << endl;

    }
    return 0;
}