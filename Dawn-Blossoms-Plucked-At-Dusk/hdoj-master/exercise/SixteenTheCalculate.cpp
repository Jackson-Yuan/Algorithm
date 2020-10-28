/**
 * The input contains several test cases, please process to the end of the file.
 * Each case consists of two hexadecimal integers A and B in a line seperated by a blank.
 * The length of A and B is less than 15.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) {
        bool tokenA, tokenB;
        /**
         * 判断符号
         * */
        if (a[0] == '+') {
            tokenA = true;
            a = a.substr(1);
        } else if (a[0] == '-') {
            tokenA = false;
            a = a.substr(1);
        } else tokenA = true;

        if (b[0] == '+') {
            tokenB = true;
            b = b.substr(1);
        } else if (b[0] == '-') {
            tokenB = false;
            b = b.substr(1);
        } else tokenB = true;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int indexA = 0, indexB = 0;
        long long valA = 0, valB = 0;
        long long base = 1;
        while (indexA < a.length()) {
            long long tmpA;
            if (a[indexA] >= 'A' && a[indexA] <= 'Z') {
                tmpA = a[indexA] - 'A' + 10;
            } else tmpA = a[indexA] - '0';

            valA += tmpA * base;
            base = base * 16;
            ++indexA;
        }

        if (!tokenA) valA = -valA;

        base = 1;
        while (indexB < b.length()) {
            long long tmpB;
            if (b[indexB] >= 'A' && b[indexB] <= 'Z') {
                tmpB = b[indexB] - 'A' + 10;
            } else tmpB = b[indexB] - '0';

            valB += tmpB * base;
            base = base * 16;
            ++indexB;
        }

        if (!tokenB) valB = -valB;

        long long res = valA + valB;
        bool token = true;
        if (res < 0) {
            res = -res;
            token = false;
        }
        string str;
        if (res == 0) str.append(1, '0');
        while (res) {
            long long tmp = res % 16;
            char target;
            if (tmp >= 10) {
                target = 'A' + tmp - 10;
            } else {
                target = '0' + tmp;
            }

            str.append(1, target);
            res /= 16;
        }

        if (!token) str.append(1, '-');
        reverse(str.begin(), str.end());
        cout << str << endl;
    }

    return 0;
}