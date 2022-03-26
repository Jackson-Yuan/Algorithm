#include "iostream"
#include "vector"

using namespace std;
/**
 * ����һ������ n ������ 0 <= i <= n �е�ÿ�� i ������������Ʊ�ʾ�� 1 �ĸ��� ������һ������Ϊ n + 1 ������ ans ��Ϊ�𰸡�
 * ���ӣ�https://leetcode-cn.com/problems/counting-bits/
 * */


/**
 * ͳ��һ�����Ķ�������1���ֵĴ���
 *
 * ���ַ����������ֺ�˵�����������ڸ�����
 * �ڶ�������������������Ҫ�涨��1�����ƴ�����
 * ��һ�����������������ҿ飬����˼������x & ��x - 1�� ��ʹ��x�����һ��1��Ϊ0
 * 
 * */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; ++i) {
            ans.push_back(judge(i));
        }

        return ans;
    }


    int judge(int val) {
        int count = 0;
        while (val) {
            val = val & (val - 1);
            ++count;
        }

        return count;
    }

    int judge2(int val) {
        int count = 0;
        int i = 1;
        while (i != INT_MIN) {
            if (val & i) ++count;
            i = i << 1;
        }

        return count;
    }

    int judge3(int val) {
        int count = 0;
        while (val) {
            if (val & 1 == 1) ++count;

            val >>= 1;
        }

        return count;
    }
};


