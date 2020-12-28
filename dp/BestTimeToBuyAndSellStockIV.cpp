/**
 * ����һ����������prices �����ĵ� i ��Ԫ��prices[i] ��һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�
 * ���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ס�
 * ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
 * */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            /**ÿһ�ֵ�buy[i][0]��������Ҫ��ʼ����sell[i][0]����Ҫ������״̬ת��������*/
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};
/**
 * ������ȷһ�¸�����������һ�ʽ���
 * buy�����ʾ����i��ǡ�ý���j�ʽ��ף��ҳ��й�Ʊ���������
 * sell�����ʾ����i��ǡ�ý���j�ʽ��ף��Ҳ����й�Ʊ���������
 * ����buy[i][j]����������״̬��Դ������i-1�첻���й�Ʊ����sell[i-1][j]����ΪҪ���й�Ʊ�����ü�ȥprices[i]����sell[i-1][j] - prices[i]
 * ���ߵ�i-1����й�Ʊ�����ճ�buy[i-1][j]
 *
 * ͬ�����sell[i][j]������i-1�첻���й�Ʊ�����ճ�sell[i-1][j]
 * ����i-1����й�Ʊ�������϶�Ҫ������Ϊsell[i-1][j-1] + prices[i]
 *
 * ת�Ʒ������꣬�Ϳ��߽���
 * ����buy����sell��iΪ0��j��1��k��ֵ�����������
 * Ψ��i = 0 j = 0ʱ��buy[i][j] = -prices[0]��������ǡ�ý�����0�ʽ��ף������ֳ��й�Ʊ����ôֻ�����ֵ����Ҫ��
 * sell[i][j]Ҳ��һ������
 * */