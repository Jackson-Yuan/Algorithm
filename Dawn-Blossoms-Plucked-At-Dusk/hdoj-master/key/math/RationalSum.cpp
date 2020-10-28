/**
 * 算法笔记 p203
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>

using namespace std;
struct point {
    long long son;
    long long mother;
};

long long gcd(long long a, long long b) {
    /**保证最大公约数为正以确保符号出现在分子上，且出现 a = -6 b = 3这种情况时，全部先转为正，更符合运行逻辑*/
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    if (a > b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    while (a) {
        long long tmp = b % a;
        b = a;
        a = tmp;
    }
    return b;
}

int main() {
    int n;
    stack<point> s;
    cin >> n;
    if (n == 0) return 0;
    for (int i = 0; i < n; ++i) {
        point current;
        scanf("%lld/%lld", &current.son, &current.mother);
        s.push(current);
    }

    while (s.size() > 1) {
        point a = s.top();
        s.pop();
        point b = s.top();
        s.pop();
        long long min = gcd(a.mother, b.mother);
        long long max = (a.mother * b.mother) / min;
        a.son *= max / a.mother;
        b.son *= max / b.mother;
        point current;
        current.mother = max;
        current.son = a.son + b.son;
        /**分子为0照样可以gcd*/
        min = gcd(current.son, current.mother);
        current.mother /= min;
        current.son /= min;

        s.push(current);
    }

    point res = s.top();
    if (res.son / res.mother == 0) {
        if (res.son != 0) cout << res.son << "/" << res.mother;
        else cout << res.son;
    } else if (res.son / res.mother == res.son) {
        cout << res.son;
    } else {
        cout << res.son / res.mother << " ";
        res.son = res.son % res.mother;
        cout << res.son << "/" << res.mother;
    }

    return 0;
}
/**
 * 分数的加法，注意分子为0情况
 * */