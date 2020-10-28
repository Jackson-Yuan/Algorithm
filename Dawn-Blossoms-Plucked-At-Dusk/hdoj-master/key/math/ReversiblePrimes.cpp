/**
 * 算法笔记 p213
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
    if (val <= 1) return false;/**注意*/
    int end = (int) sqrt(val);
    for (int i = 2; i <= end; ++i) {
        if (val % i == 0) return false;
    }

    return true;
}

bool reverse(int val, int base) {
    string target;
    while (val) {
        int tmp = val % base;
        char tmpValue;
        if (tmp < 10) tmpValue = '0' + tmp;
        else tmpValue = 'A' + tmp - 10;
        target.append(1, tmpValue);
        val /= base;
    }

    int sum = 0;
    for (int i = 0; i < target.length(); ++i) {
        int tmp;
        if (target[i] >= '0' && target[i] <= '9') tmp = target[i] - '0';
        else tmp = 10 + target[i] - 'A';
        sum = sum * base + tmp;
    }

    return judge(sum);
}

int main() {
    int n, d;
    while (true) {
        cin >> n;
        if (n < 0) break;
        cin >> d;
        if (judge(n) && reverse(n, d)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }

    return 0;
}