/**
 * 现在有一长度为N的字符串,满足一下条件:
 * (1) 字符串仅由A,B,C,D四个字母组成;
 * (2) A出现偶数次(也可以不出现);
 * (3) C出现偶数次(也可以不出现);
 * 计算满足条件的字符串个数.
 * 当N=2时,所有满足条件的字符串有如下6个:BB,BD,DB,DD,AA,CC.
 * 由于这个数据肯能非常庞大,你只要给出最后两位数字即可.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int getSum(long long base, long long val) {
    int res = 1;
    while (val) {
        if (val & 1) {
            res *= base;
            res %= 100;
        }
        val = val >> 1;
        base *= base;
        base %= 100;
    }

    return res;
}

int main() {
    int t;
    while (true) {
        cin >> t;
        if (t == 0) break;
        int sum = t;
        while (t--) {
            long long n;
            cin >> n;
            int res = (getSum(4, n - 1) + getSum(2, n - 1)) % 100;
            cout << "Case " << sum - t << ": " << res << endl;
        }

        cout << endl;
    }


    return 0;
}
/**
 * 这道题推导据传为泰勒级数，也是佛了，暂时放弃
 * 纯当复习快速幂
 * 同时注意一下__int64这个类型，将int型扩展至64位 与long long一致
 * */