#include "iostream"
#include "string"
#include "math.h"
#include "set"

using namespace std;

/**
 * 给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。
 * “最近的”定义为两个整数差的绝对值最小。
 * */

/**
 * 本体本质是利用给定数字字符串的前半部分来获取可能的几个候选项，并分奇数，偶数来讨论还原回文串的区别
 * 若给定串为“abcd”，前半部分t为ab，若为“abcde”，前半部分t为abc
 * 候选的为t-1, t, t+1 以及+1，-1导致的进位，退位
 * */
class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.length();
        long cur = str2Long(s);
        set<long> ss;
        ss.insert((long) pow(10, n - 1) - 1);
        ss.insert((long) pow(10, n) + 1);
        long t = str2Long(s.substr(0, (n + 1) / 2));
        for (long i = t - 1; i <= t + 1; i++) {
            long temp = -1;
            if (n % 2 == 0) temp = getNum(i, true);
            else temp = getNum(i, false);
            if (temp != cur) ss.insert(temp);
        }
        long ans = -1;
        for (long i : ss) {
            if (ans == -1) ans = i;
            else if (abs(i - cur) < abs(ans - cur)) ans = i;
            else if (abs(i - cur) == abs(ans - cur) && i < ans) ans = i;
        }
        return to_string(ans);
    }

    long getNum(long k, bool isEven) {
        string sb = to_string(k);
        int idx = isEven ? sb.length() - 1 : sb.length() - 2;
        while (idx >= 0) sb.append(1, sb[idx--]);
        return str2Long(sb);
    }


    long str2Long(string s) {
        long base = 1;
        long ans = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            long cur = s[i] - '0';
            ans += cur * base;
            base *= 10;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.nearestPalindromic("4922");
}