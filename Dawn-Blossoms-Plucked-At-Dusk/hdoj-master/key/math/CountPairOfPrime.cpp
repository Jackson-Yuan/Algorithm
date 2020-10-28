/**
 * 算法笔记 p209
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> notPrime(n + 1, false);
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if (notPrime[i]) continue;
        prime.push_back(i);
        long long start = i;
        for (long long j = start * start; j <= n; j += start) {
            notPrime[j] = true;
        }

    }

    int count = 0;
    for (int i = 1; i < prime.size(); ++i) {
        if (prime[i] - prime[i - 1] == 2) ++count;
    }

    cout << count << endl;
    return 0;
}
/**
 * 素数筛法，但有个小细节，再倍乘的过程中，因为这个题目最大n可以99999，若果j为int型进行倍乘，为溢出，变成负数，出现数组访问异常
 * 这时用long long即可解决
 * */