/**
 * 给定一个总页码n（页码从1开始），计算出1 ~ n这些页码，0 ~ 9出现的次数
 * */
#include "iostream"
#include "vector"
#include "cmath"

using namespace std;
vector<long long> ans(10, 0);

long long numberLen(long long val) {
    long long count = 0;
    do {
        ++count;
        val /= 10;
    } while (val);

    return count;
}

long long count(long long val) {
    long long len = numberLen(val);
    if (len == 1) {
        for (int i = 0; i <= val; ++i) {
            ++ans[i];
        }
        return -1;
    }
    long long base = pow(10, len - 1);
    long long fist = val / base;
    for (int i = 0; i < fist; ++i) {
        ans[i] += pow(10, len - 1);
        for (int j = 0; j < ans.size(); ++j) {
            /**0000 ~ 9999 0 ~ 9出现的次数 公式*/
            ans[j] += (len - 1) * (long long) pow(10, len - 2);
        }
    }

    long long remain = val - fist * base + 1;
    ans[fist] += remain;
    return remain - 1;
}

int main() {
    long long val;
    cin >> val;
    long long len = numberLen(val);
    /**删除前导0*/
    for (int i = 0; i < len; ++i) {
        ans[0] -= pow(10, i);
    }
    /**补偿重复，假如有三位，第二位即00被重复算了一回，四位000 00被重复算了一回*/
    ans[0] += len - 2;
    while (val != -1) {
        val = count(val);
    }
    for (auto cur : ans) {
        cout << cur << endl;
    }
}