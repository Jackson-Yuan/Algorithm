/**
 * 算法笔记 p221
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

bool judge(int val) {
    if (val <= 1) return false;
    int end = (int) sqrt(val);
    for (int i = 2; i <= end; ++i) {
        if (val % i == 0) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    cout << n << "=";
    if (n == 1) {
        cout << "1";
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        if (judge(i)) {
            int val = i;
            int count = 0;
            while (n % val == 0) {
                ++count;
                n /= val;
            }
            if (count == 1) cout << val;
            else if (count > 1) cout << val << "^" << count;

            if (n != 1 && count != 0) cout << "*";

            if (n == 1) break;
        }
    }

    return 0;
}
/**
 * 此题一些细节说一下，一个是素数筛法虽然快 但一旦数组开打了就比较慢，且巨量空间数组用vector慢的一匹
 * 且此种分解质因数题目，用素数筛法一旦n很大，会做很多无用功且耗时
 * 所以分解质因数还是用最基本的判断素数的方法
 * */