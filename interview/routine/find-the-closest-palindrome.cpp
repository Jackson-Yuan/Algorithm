#include "iostream"
#include "string"
#include "math.h"
#include "set"

using namespace std;

/**
 * ����һ����ʾ�������ַ��� n ��������������Ļ��������������������������ֹһ�������ؽ�С���Ǹ���
 * ������ġ�����Ϊ����������ľ���ֵ��С��
 * */

/**
 * ���屾�������ø��������ַ�����ǰ�벿������ȡ���ܵļ�����ѡ�����������ż�������ۻ�ԭ���Ĵ�������
 * ��������Ϊ��abcd����ǰ�벿��tΪab����Ϊ��abcde����ǰ�벿��tΪabc
 * ��ѡ��Ϊt-1, t, t+1 �Լ�+1��-1���µĽ�λ����λ
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