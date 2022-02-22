#include "iostream"
#include "vector"

using namespace std;


/**
 * ����һ�㷽������ֱ��˫��forѭ������ö��
 * ���ǲ��������룬��Ʊ���������������۸��ȥ��С����۸� �Ҷ�Ӧʱ��Ҳ��������߼�
 * �������飬���ǿ��Խ���ǰ������Ԫ����Ϊ��Ҫ�����ļ۸�ǰ��ά��һ��֮ǰ����С�����
 * ���������꣬���۸�Ҳ������
 * */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        if (prices.size() < 2) return ans;
        int minIn = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - minIn > ans) ans = prices[i] - minIn;

            if (prices[i] < minIn) minIn = prices[i];
        }

        return ans;
    }
};