#include "iostream"
#include "vector"

using namespace std;
/**
 * ������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
 * ��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k����ͬ��Ԫ�ء�
 * */

/**
 * ������Ѱ��һ�������е�k�����Ԫ��
 * һ������Ѱ�ҵ�k��������СԪ�أ������Ե�һ��������ֱ������Ȼ��������ȡ���ɣ���һ��ʱ�临�Ӷ�Ϊo��nlogn��
 *
 * ��߽���һ��o��n���㷨�����������û��ֿ��ŵĻ��ֺ���
 * ����֪�����ŵĻ��ֺ�����һ�ο���ȷ��һ����������λ�ã���������Ѱ�ҵ�k��Ԫ���뷨һ�£�����ֻ��Ҫ�ҵ�
 * k��Ԫ�أ�ǰk-1���Ƿ������Ҳ����ģ�ֻҪ�ܱ�֤ǰk-1�������С��ϵ���ɣ�
 * ���ǿ������������϶���������Ѱ�ң��ڿ�����ÿ�λ��ֺ󣬶�Ҫ�����ߵݹ飬������ֻҪ��һ�ߵݹ鼴��
 *
 * �ڻ���ʱ������������ٲ��裬��ֹ�㷨�˻���ƽ��ʱ�临�Ӷȣ�ÿ��ѡȡ���������һ��Ϊ������ô��Ҫ����n�Σ�ÿ�δ���ʱ����o��n����
 *
 * ����Ϊʲôƽ����o��n�������ڼ�ס�����ˣ��㷨����9.2���Ƶ�������������û����
 * */
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int split = partion(start, end, nums);
            if (split == k - 1) return nums[split];
            else if (split > k - 1) end = split - 1;
            else {
                start = split + 1;
            }
        }

        return -1;
    }


    int partion(int start, int end, vector<int> &nums) {
        int randomIndex = rand() % (end - start + 1) + start;
        swap(nums[start], nums[randomIndex]);
        int compare = nums[start];

        while (start < end) {
            while (start < end && nums[end] <= compare) --end;
            nums[start] = nums[end];

            while (start < end && nums[start] >= compare) ++start;
            nums[end] = nums[start];
        }

        nums[start] = compare;
        return start;
    }
};

