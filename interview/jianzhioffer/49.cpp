#include "iostream"
#include "vector"

using namespace std;


/**
 * �ҳ���n��ĳ���
 * ����������������жϳ���
 * �������ʱ�����������룬��ĳ���������С�ĳ���*2��*3��*5����
 * ����ֻ�轫С�ĳ���Ԥѡ����������ͨ��*2 *3 *5 �������ֱ��ָ����n��
 * �����뷨������ɸ������
 * */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n, 0);
        ans[0] = 1;
        int next = 1;
        int point2 = 0, point3 = 0, point5 = 0;

        while (next < n) {
            int val = min(min(ans[point2] * 2, ans[point3] * 3), ans[point5] * 5);
            ans[next] = val;

            while (2 * ans[point2] <= ans[next]) ++point2;
            while (3 * ans[point3] <= ans[next]) ++point3;
            while (5 * ans[point5] <= ans[next]) ++point5;

            ++next;
        }

        return ans[n - 1];
    }
};

