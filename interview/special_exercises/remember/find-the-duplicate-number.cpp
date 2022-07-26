#include "iostream"
#include "vector"

using namespace std;
/**
 * ����һ������n + 1 ������������nums �������ֶ���[1, n]��Χ�ڣ����� 1 �� n������֪���ٴ���һ���ظ���������
 * ���� nums ֻ�� һ���ظ������� ����������ظ����� ��
 * ����ƵĽ���������� ���޸� ���� nums ��ֻ�ó����� O(1) �Ķ���ռ䡣
 * ���ӣ�https://leetcode.cn/problems/find-the-duplicate-number
 * */

/**
 * �����޷���˵ʲô��ֱ�Ӽǽⷨ������ת��Ϊ�����������ཻ�㣨�Ҹ�����Ŀ����������سɻ���
 *
 * ������[1, 3, 4, 2]
 * ���ת������0->1 1->3, 3->2, 2->4, 4->Խ�磨null��
 *
 * ��������[1, 3, 4, 2, 2]
 * ��ת������0->1, 1->3, 3->2, 2->4, 4->2 (��ʼ�ɻ�)
 * */
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution solution;
    cout << solution.findDuplicate(nums);
}

