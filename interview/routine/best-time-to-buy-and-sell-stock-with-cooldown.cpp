#include "iostream"
#include "vector"

using namespace std;

/**
 * ����һ����������prices�����е�prices[i]��ʾ��i��Ĺ�Ʊ�۸�
 * ���һ���㷨����������������������Լ�������£�����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ��:
 * ������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
 * ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
 * ���ӣ�https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 * */

/**
 * ��ѽⷨ����̬�滮��ֻ��״̬�Ķ�����Ҫ��ˮƽ���ܶ������
 * ���������ת�Ʒ��̺ܺ�д
 * */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: ���ϳ��й�Ʊ���������
        // f[i][1]: ���ϲ����й�Ʊ�����Ҵ����䶳���е��ۼ��������
        // f[i][2]: ���ϲ����й�Ʊ�����Ҳ����䶳���е��ۼ��������
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};

/**
 * �������Ѱ���仯�ݹ�д��
 * ��ô˵�أ�ps����洢��startλ�ÿ�ʼ�����Ʊ֮���������棨�������Σ�
 * ѭ�����������ڽ�λ������һ�αȽϣ��൱�ڱȽϲ�ͬ�ݹ鿪ʼ�����ֵ��Ϊɶֻ�Ƚ���һ������Ϊ��һ���ĵݹ����Ƚ�����һ�����ȼ���ö�������еݹ��������ֵ��
 * ţ��
 * */
class Solution2 {
private:
    vector<int> ps;
public:
    int maxProfit(vector<int> &prices) {
        ps = vector<int>(prices.size(), INT_MAX);
        return deal(0, prices);
    }

    int deal(int start, vector<int> &prices) {
        if (start >= prices.size()) {
            return 0;
        }

        int max_profit = 0;

        if (ps[start] != INT_MAX) {
            return ps[start];
        }

        for (int i = start + 1; i < prices.size(); i++) {
            int profit_now = prices[i] - prices[start];
            int profit_after = deal(i + 2, prices);
            int profit_total = profit_now + profit_after;

            max_profit = max(max_profit, profit_total);
        }

        max_profit = max(max_profit, deal(start + 1, prices));
        ps[start] = max_profit;
        return max_profit;
    }
};