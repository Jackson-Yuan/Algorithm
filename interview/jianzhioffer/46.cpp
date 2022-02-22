#include "iostream"
#include "vector"

using namespace std;

/**
 * ���ַ����ַ���
 *
 * �۲켸����������ʵ�������Ʋ��Ͻ�������⣺
 * �� ����Ϊn���ַ�����������n-1������n-2���ȣ�����n-2����Ҫ�ж�һ�µ�ǰ�ַ�������λ�Ƿ��ڸ�����Χ֮��
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

