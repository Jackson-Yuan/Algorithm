#include "iostream"
#include "vector"

using namespace std;

/**
 * ˫ָ���Ӧ�ã���ʼһ��ָ��ͷ��һ��ָ��β
 * ͷβ�ֱ�Ѱ�ҵ���һ������������ż������������
 * */
class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] & 1) ++begin;
            else {
                if (nums[end] & 1) {
                    int tmp = nums[end];
                    nums[end] = nums[begin];
                    nums[begin] = tmp;
                    ++begin;
                    --end;
                } else {
                    --end;
                }
            }
        }

        return nums;
    }
};
