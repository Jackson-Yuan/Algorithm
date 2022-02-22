#include "iostream"
#include "vector"

using namespace std;

/**
 * ���ö��ֵ�˼��ֱ�Ѱ��target��һ�γ��������һ�γ��ֵ�λ��
 * ���ڶ��ֵ�ʹ�ã�����������ʵ�͵������ܷ��ö��ֽ��
 * ע����ֵ�ѭ����ֹ���� ��С�ڵ���
 * */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int start = getFirst(nums, target);
        int end = getLast(nums, target);

        if (start != -1 && end != -1) return end - start + 1;
        else return 0;
    }

    int getFirst(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;

            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid - 1] == target) right = mid - 1;
                else return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else left = mid + 1;
        }

        return -1;
    }

    int getLast(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;

            if (nums[mid] == target) {
                if (mid + 1 < nums.size() && nums[mid + 1] == target) left = mid + 1;
                else return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else left = mid + 1;
        }

        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    cout << solution.search(nums, 8);
}

