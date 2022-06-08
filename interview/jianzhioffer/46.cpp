#include "iostream"
#include "vector"

using namespace std;

/**
 * 数字翻译字符串
 *
 * 观察几个用例，其实过程类似不断解决子问题：
 * 即 长度为n的字符串，依赖于n-1长度与n-2长度，其中n-2长度要判断一下当前字符串后两位是否在给定范围之间
 * */

class Solution {
public:
    int translateNum(int num) {
        string val = getStr(num);
        vector<int> dp(val.length() + 1, 1);
        for (int i = 2; i <= val.length(); ++i) {
            dp[i] = dp[i - 1];
            string tmp;
            tmp.append(1, val[i - 2]);
            tmp.append(1, val[i - 1]);
            if (tmp[0] != '0' && tmp >= "0" && tmp <= "25") dp[i] += dp[i - 2];
        }
        return dp[val.length()];
    }

    string getStr(int num) {
        string res;
        do {
            int tmp = num % 10;
            res.append(1, '0' + tmp);
            num /= 10;
        } while (num != 0);
        reverse(res.begin(), res.end());
        return res;
    }

