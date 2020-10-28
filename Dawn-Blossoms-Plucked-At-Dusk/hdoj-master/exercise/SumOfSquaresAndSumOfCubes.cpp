/**
 *  给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。
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
    int m, n;
    while (cin >> m >> n) {
        if (m > n) {
            int tmp = m;
            m = n;
            n = tmp;
        }

        int sumA = 0, sumB = 0;
        for (int i = m; i <= n; ++i) {
            if (i % 2 == 0) {
                sumA += (int) pow(i, 2);
            } else {
                sumB += (int) pow(i, 3);
            }
        }

        cout << sumA << " " << sumB << endl;
    }

    return 0;
}