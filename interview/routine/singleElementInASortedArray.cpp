#include "iostream"
#include "vector"

using namespace std;

/**
 * ����һ������������ɵ��������飬����ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ�Ρ�
 * �����ҳ�������ֻ����һ�ε��Ǹ�����
 * ����ƵĽ�������������� O(log n) ʱ�临�ӶȺ� O(1) �ռ临�Ӷȡ�
 * */

/**
 * ����ֻ��һ����������������������ż������ ��һ��ͨ�õĽⷨ���Ǿ���ֱ�Ӱ�����Ԫ�ؽ����������
 * ż�����������֮��ȫΪ0����ôʣ���Ǹ��������������֮��ض����Ǹ�ֵ
 *
 *
 * �����������˸�������������ʹ��logn���Ӷȳ�Ϊ���ܡ�
 * ע��۲죬ֻ����һ�ε��������߱�Ȼ����ż���������������У�����Ϊ������ͬ����������һ��
 * ����ߣ���num[x]=nums[x+1],��x��Ϊż�������ұߣ�nums[x]=nums[x+1].��x��Ϊ����
 * ���ǽ��ж������ĸ�����ѹ������Ҫ���������ǿ����ڶ���ʱ��midֵ����ż�Խ����ж�
 * ��Ϊż������һ������Ϊ�濴��ǰһ�죬����ȣ������������ڵ�һ����midλ�õ��ұߣ���left=mid+1
 * �����ȣ������һ����midλ�õ��ұߣ���right=mid��Ϊʲô����mid-1����Ϊ���Ȳ�����Ϊ�ǵ�һ���ұߵ�����
 * ���п��ܾ��ǵ�һ������
 * */
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            int a = nums[mid];
            int b;
            if (mid % 2 == 0) {
                if (mid + 1 < nums.size()) b = nums[mid + 1];
                else b = nums[mid];
            } else {
                if (mid - 1 >= 0) b = nums[mid - 1];
                else b = nums[mid];
            }
            if (a == b) {
                left = mid + 1;
            } else right = mid;
        }

        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3};

    cout << solution.singleNonDuplicate(nums);
}
