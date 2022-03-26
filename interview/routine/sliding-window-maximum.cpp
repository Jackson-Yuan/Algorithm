#include "iostream"
#include "vector"
#include "queue"

using namespace std;


/**
 * ����һ���������� nums����һ����СΪk�Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k�����֡���������ÿ��ֻ�����ƶ�һλ��
 * ���ػ��������е����ֵ��
 * ���ӣ�https://leetcode-cn.com/problems/sliding-window-maximum
 * */

/**
 * ���⣬��һ����������ά��һ����СΪk������
 * ���������������һ�ֽⷨ���������У��뵥��ջ���֣�����������ά��������ֵ����
 * ������ջ������ά������Ĵ�С��ϵ
 * */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < k; ++i) {
            /**
             * ��߹�ϵ�Ƚ�Ҫ���ϵ��ڣ���ʹ��ȣ���Ϊֻ��k�� Ҫ�����µ�
             * */
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);


            while (q.front() <= i - k) {
                q.pop_front();
            }

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};

