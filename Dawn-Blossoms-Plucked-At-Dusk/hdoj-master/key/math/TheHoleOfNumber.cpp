/**
 * 算法笔记 p193
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int sortBySmallOrBig(int val, bool token) {
    vector<int> res;
    for (int i = 0; i < 4; ++i) {
        res.push_back(val % 10);
        val /= 10;
    }
    if (token) sort(res.begin(), res.end());
    else sort(res.begin(), res.end(), cmp);
    int value = 0;
    int base = 1;
    for (int i = res.size() - 1; i >= 0; --i) {
        value += res[i] * base;
        base *= 10;
    }

    return value;
}

int main() {
    int target;
    cin >> target;
    while (true) {
        int big = sortBySmallOrBig(target, false);
        int small = sortBySmallOrBig(target, true);
        int res = big - small;
        printf("%04d - %04d = %04d\n", big, small, res);
        target = res;
        if (target == 0 || target == 6174) break;
    }

    return 0;
}
/**
 * 这个输入的数不仅仅是四位数，有可能是两位数，比如91，按常规的拆分，只能拆两个数1与9，算出来big值为19
 * 按照题目要求应该为9100，因为我的91换成四位为0 0 1 9
 * */