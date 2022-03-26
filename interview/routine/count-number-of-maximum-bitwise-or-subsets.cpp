#include "iostream"
#include "vector"

using namespace std;

/**
 * ����һ���������� nums �������ҳ� nums �Ӽ� ��λ�� ���ܵõ��� ���ֵ �������ذ�λ���ܵõ����ֵ�� ��ͬ�ǿ��Ӽ�����Ŀ ��
 * ������� a ���������� b ɾ��һЩԪ�أ���ɾ�����õ�������Ϊ���� a ������ b ��һ�� �Ӽ� �����ѡ�е�Ԫ���±�λ�ò�һ��������Ϊ�����Ӽ� ��ͬ ��
 * ������ a ִ�� ��λ�򣬽������ a[0] OR a[1] OR ... OR a[a.length - 1]���±�� 0 ��ʼ����
 * ���ӣ�https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets
 * */

/**
 * �Ը������Ӽ���Ŀ����ʵ���Ƕ�ÿ��Ԫ��ѡ�벻ѡ����·����������dfs��������
 *
 * ����ṩһ����ѭ����ʽ������˼·
 *
 * �����n��Ԫ�أ�ÿ��Ԫ��ѡ�벻ѡ ��2��n�η������ǿ�����һ������Ϊn�Ķ���������0��1����
 * �Զ�Ӧλ��Ԫ�ص�ȡ��
 * */
class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue) {
                cnt++;
            } else if (cur > maxValue) {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};


int main() {
    vector<int> nums = {3, 2, 1, 5};

    Solution solution;
    cout << solution.countMaxOrSubsets(nums);
}

