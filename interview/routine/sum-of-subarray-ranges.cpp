#include "iostream"
#include "vector"
#include "stack"

using namespace std;
/**
 * ����һ���������� nums ��nums �У�������� ��Χ �������������Ԫ�غ���СԪ�صĲ�ֵ��
 * ���� nums �� ���� �����鷶Χ�� �� ��
 * ��������������һ������ �ǿ� ��Ԫ�����С�
 * ���ӣ�https://leetcode-cn.com/problems/sum-of-subarray-ranges
 * */

/**
 * �����һ�ַ�����ֱ�ӱ�������bb
 * ���˵һ��o(n)ʱ�临�Ӷȵķ��������õ���ջ���������
 * ����ջ���Ǳ���ջ��Ԫ���ǰ��յ������ߵݼ�˳�򱣴棬������
 * һ��Ԫ�ز�����Ļ����ͷ����ջ��Ԫ�س�ջ��ֱ����������Ϊֹ��������һά����Ѱ�ҵ�һ������ĳ����������
 *
 * �⵽��Ŀ�Ǽ���������������������ֵ����Сֵ�ĺ�
 * ��һ���뷨����ʵ����ÿ������Ϊ�����������������ֵ����p����Сֵ����q�Ĳ�ֵ�˱���p-q��* val
 * �����ѵ��������ȷ��p��q������Ҫȷʵ����ĳ��Ԫ��a��������Ϊk����p��q����ΪҪ�����������飬����ֻҪ
 * Ѱ���Ե�ǰԪ��Ϊ�����㣬������Ѱ�ҵ�һ������aԪ�ص���������Ϊi��j ��p�ĸ���Ϊ��k - i��*��j - k��
 * qͬ������ΨһҪ���ľ���ȷ��i��j��λ�ã���ʱ����ջ���Ժܺõؽ���������⣬���ǿ��Դ��ײ�������ȷ��
 * i����β������ȷ��j���൱�����鵹�������ײ������������ײ�����ȷ������q��Ҫ��iΪ����ά��һ���ݼ��ĵ���ջ��������һ��Ԫ��ʱ����ջ������������ջ����������
 * Ҫ�ҵ�i�������ǣ����ջѰ����һ��ջ����������ȷ����i��Ҳ���赣�ĵ�����Ԫ�ػ�Ӱ�쵽���滹δ�ж�Ԫ�ص��жϡ���Ϊ������Ԫ������Ϊ��
 * �����˸��������Ԫ�أ������Ԫ��������������Ȼ��Ȼ���ڵ�����Ԫ�أ�������С��������������Ҫ�ĵ�һ��Ԫ�ء�
 *
 *
 * ����Ϊʲô��o��n����էһ������o��n����������˼·�룬ÿ��Ԫ��ֻ��ջһ�Σ������ջһ�Σ�����ʵ����o��n��
 * */
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        stack<int> minS, maxS;

        vector<int> minLeft(nums.size(), 0);
        vector<int> minRight(nums.size(), 0);

        vector<int> maxLeft(nums.size(), 0);
        vector<int> maxRight(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            while (!maxS.empty() && nums[maxS.top()] < nums[i]) {
                maxS.pop();
            }
            minLeft[i] = (maxS.empty() ? -1 : maxS.top());
            maxS.push(i);


            while (!minS.empty() && nums[minS.top()] > nums[i]) {
                minS.pop();
            }

            maxLeft[i] = (minS.empty() ? -1 : minS.top());
            minS.push(i);
        }


        while (!minS.empty()) minS.pop();
        while (!maxS.empty()) maxS.pop();
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!maxS.empty() && nums[maxS.top()] <= nums[i]) {
                maxS.pop();
            }
            minRight[i] = (maxS.empty() ? nums.size() : maxS.top());
            maxS.push(i);


            while (!minS.empty() && nums[minS.top()] >= nums[i]) {
                minS.pop();
            }

            maxRight[i] = (minS.empty() ? nums.size() : minS.top());
            minS.push(i);
        }


        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sumMax += (long long) ((minRight[i] - i) * (i - minLeft[i])) * nums[i];
            sumMin += (long long) ((maxRight[i] - i) * (i - maxLeft[i])) * nums[i];
        }

        return sumMax - sumMin;
    }


};

int main() {
    vector<int> ans = {1, 2, 3};

    Solution solution;

    cout << solution.subArrayRanges(ans);
}