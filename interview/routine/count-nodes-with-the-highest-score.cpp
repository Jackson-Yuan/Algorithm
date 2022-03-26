#include "iostream"
#include "vector"

using namespace std;

/**
 * ����һ�ø��ڵ�Ϊ 0 �Ķ����������ܹ��� n���ڵ㣬�ڵ���Ϊ0��n - 1��ͬʱ����һ���±��0��ʼ����������parents��ʾ�������
 * ����parents[i]�ǽڵ� i�ĸ��ڵ㡣���ڽڵ� 0�Ǹ�������parents[0] == -1��
 * һ�������� ��СΪ��������ڽڵ����Ŀ��ÿ���ڵ㶼��һ����֮�����ķ��������ĳ���ڵ�����ķ����ǣ�������ڵ�����������ı�ȫ�� ɾ����
 * ʣ�ಿ�������ɸ� �ǿ�����������ڵ�� ����Ϊ������Щ���� ��С�ĳ˻���
 * ���ӣ�https://leetcode-cn.com/problems/count-nodes-with-the-highest-score
 * */

/**
 * ȥ���ڵ��ֵ����Դ����������������������������ڵ�Ϊ���ڵ�����Ƴ�ʣ��Ĵ�С�����ڵ���⣩
 * ���������˼·����ͳ�Ƴ����������ıߣ����һ�����鱣��ÿ�����������Ϊ���ڵ��������С
 * ��������ĳ����ֵ��ʱ��ֱ����ȡ���������ڵ��ֵ���ڵ�������ȥ�����������ڵ�+1����ֵ�����ڵ���⣩���������
 *
 * ������ÿ���ڵ�Ϊ���ڵ�������С���������棬ʱ�临�Ӷ��Ǵ���o��n����
 *
 * ������ʱ����������dfs���߱����߼���������С
 * */
class Solution {
private:
    long maxScore;
    long ans;
public:
    int countHighestScoreNodes(vector<int> &parents) {
        vector<int> container(parents.size(), 1);
        vector<vector<int>> link(parents.size());

        int n = parents.size();
        maxScore = INT_MIN;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            if (parents[i] != -1) {
                link[parents[i]].push_back(i);
            }
        }

        dfs(0, link);

        return ans;
    }


    int dfs(int index, vector<vector<int>> &link) {
        long score = 1;

        /**
         * �����Ƴ�������ڵ�Ϊ���ڵ�������Ƴ���Ĵ�С
         * �õ����ýڵ�������ȥ����ڵ�����������С���ټ�ȥ1������ڵ㱾ʡ��
         * */
        long all = link.size() - 1;

        for (int next : link[index]) {
            int next_val = dfs(next, link);

            score *= next_val;
            all -= next_val;
        }


        /**
         * ����Ǹ��ڵ㣬ʣ��������ڵ�Ϊ0�����ܳ�
         * */
        if (index != 0) score *= all;

        if (score == maxScore) {
            ++ans;
        } else if (score > maxScore) {
            ans = 1;
            maxScore = score;
        }


        return link.size() - all;

    }
};

