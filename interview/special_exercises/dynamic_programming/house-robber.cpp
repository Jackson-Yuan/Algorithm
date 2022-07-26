#include "iostream"
#include "vector"

using namespace std;
/**
 * ����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
 * ����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
 * ���ӣ�https://leetcode.cn/problems/house-robber
 * */

/**
 * dp���⣬dp�������壬����i��ʾǰi��������͵�����Ǯ��
 * ת�Ʒ��̣����ڵ�ǰλ��i�����������Դֻ��������Ҫô��͵������Դ��dp[i-1]����Ҫô͵����Դ��dp[i - 2] + nums[i]��
 * */
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};
