#include "iostream"
#include "vector"

using namespace std;

/**
 * ���Ⱪ����������bb
 * ����һ�¶��֣����ֵ�����ʱ�������������һά����
 * �����Ŀ��������������ķǵݼ�С���飬�������ö��������
 * ���ǿ��Եõ�ǰ���������������Ԫ�ض�����ں������������Ԫ��
 * ��Ϊ���ִ��������������ǹ̶���start��end�����䣬ȡ�м��Ԫ��
 * ���м�Ԫ�ش���startλ��Ԫ�أ�������ǰ���������������ǽ�start��Ϊmid������mid+1��
 * ͬ����С��������ں����������飬end��Ϊmid������mid+1����������Ϊmid+1��Ϊ�˱�֤
 * start������ָ��ǰ��������������һ����end����ָ�������������ĵ�һ��
 * ��Ҳ������Ѱ�ҵ�Ŀ������������ڴ��뷨��ѭ��������Ҳ��֮��������startλ�õ�Ԫ��Ҫ����ڵ���endλ�õ�Ԫ��
 * �������������������������Ǹ�˳�����飬��ת��0����
 *
 * ��Ҳ����ôһ������硾1��0��1��1��1������1��1��1��0��1������Ҳ������Ŀ���������������������뷨�޷��ж���������
 * ǰ�滹�Ǻ��棬ֻ������˳�����
 *
 *
 * �������������࣬һ������Լ���ڲ�����
 * */
class Solution {
public:
    int minArray(vector<int> &numbers) {
        if (numbers.empty()) return 0;

        int start = 0, end = numbers.size() - 1;

        while (numbers[start] >= numbers[end]) {
            int mid = (end - start) / 2 + start;

            if (end - start == 1) {
                return numbers[end];
            }

            if (numbers[start] == numbers[mid] && numbers[mid] == numbers[end]) {
                int ans = INT_MAX;
                for (int i = start; i <= end; ++i) {
                    if (numbers[i] < ans) ans = numbers[i];
                }

                return ans;
            }

            if (numbers[mid] >= numbers[start]) {
                start = mid;
            } else {
                end = mid;
            }

        }

        return numbers[start];
    }
};
