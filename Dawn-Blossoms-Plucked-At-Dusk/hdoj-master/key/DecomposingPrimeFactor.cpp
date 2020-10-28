/**
 * 质因数分解
 * 首先，先介绍一个定理
 * 任何数都可以分解成多个质数的乘积
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
        vector<bool> notPrime(n + 1, false);
        vector<int> prime;
        for (int i = 2; i <= n; ++i) {
            if (notPrime[i]) continue;
            prime.push_back(i);
            int val = 2;
            while (i * val <= n) {
                notPrime[i * val] = true;
                ++val;
            }
        }

        vector<int> res;
        for (int j = 0; j < prime.size(); ++j) {
            while (n % prime[j] == 0) {
                res.push_back(prime[j]);
                n /= prime[j];
            }

            if (n == 0) break;
        }

        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i != res.size() - 1) cout << "*";
        }

        cout << endl;
    }

    return 0;
}