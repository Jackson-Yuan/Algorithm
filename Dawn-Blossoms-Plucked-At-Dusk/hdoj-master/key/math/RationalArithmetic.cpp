/**
 * 算法笔记 p205
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
struct point {
    long long son;
    long long mother;
};

void printRational(point target) {
    bool token = false;
    if (target.son < 0) token = true;
    if (token) cout << "(";
    if (target.son / target.mother == 0) {
        if (target.son != 0) cout << target.son << "/" << target.mother;
        else cout << target.son;
    } else if (target.son / target.mother == target.son) cout << target.son;
    else {
        if (target.son < 0) {
            cout << "-";
            target.son = -target.son;
        }
        cout << target.son / target.mother << " ";
        target.son %= target.mother;
        cout << target.son << "/" << target.mother;
    }
    if (token) cout << ")";

}

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

void add(point a, point b) {
    long long max = gcd(a.mother, b.mother);
    long long min = (a.mother * b.mother) / max;
    point res;
    res.mother = min;
    res.son = (a.son * (min / a.mother)) + (b.son * (min / b.mother));
    max = gcd(res.son, res.mother);
    res.son /= max;
    res.mother /= max;

    printRational(a);
    cout << " + ";
    printRational(b);
    cout << " = ";
    printRational(res);

}

void sub(point a, point b) {
    long long max = gcd(a.mother, b.mother);
    long long min = (a.mother * b.mother) / max;
    point res;
    res.mother = min;
    res.son = (a.son * (min / a.mother)) - (b.son * (min / b.mother));
    max = gcd(res.son, res.mother);
    res.son /= max;
    res.mother /= max;

    printRational(a);
    cout << " - ";
    printRational(b);
    cout << " = ";
    printRational(res);
}

void multiple(point a, point b) {
    point res;
    res.mother = a.mother * b.mother;
    res.son = a.son * b.son;
    long long max = gcd(res.son, res.mother);
    res.son /= max;
    res.mother /= max;

    printRational(a);
    cout << " * ";
    printRational(b);
    cout << " = ";
    printRational(res);
}

void divide(point a, point b) {
    printRational(a);
    cout << " / ";
    printRational(b);
    cout << " = ";
    if (b.son == 0) {
        cout << "Inf";
        return;
    }

    long long tmp = b.son;
    b.son = b.mother;
    b.mother = tmp;
    if (b.mother < 0) {
        b.mother = -b.mother;
        b.son = -b.son;
    }

    point res;
    res.mother = a.mother * b.mother;
    res.son = a.son * b.son;
    long long max = gcd(res.son, res.mother);
    res.son /= max;
    res.mother /= max;

    printRational(res);

}

int main() {
    point a, b;
    scanf("%lld/%lld", &a.son, &a.mother);
    scanf("%lld/%lld", &b.son, &b.mother);

    long long maxA = gcd(a.son, a.mother);
    long long maxB = gcd(b.son, b.mother);
    a.son /= maxA;
    a.mother /= maxA;
    b.son /= maxB;
    b.mother /= maxB;

    add(a, b);
    cout << endl;
    sub(a, b);
    cout << endl;
    multiple(a, b);
    cout << endl;
    divide(a, b);

    return 0;
}