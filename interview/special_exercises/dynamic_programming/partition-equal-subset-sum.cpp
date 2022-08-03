#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
/**
 * ����һ�� ֻ�����������ǿ����� nums�������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
 * ���ӣ�https://leetcode.cn/problems/partition-equal-subset-sum/
 * */

/**
 * ֱ��ת��Ϊ�౳�����⣬dp������������ǰi�����У��ܷ�ѡ������ƴ�ճ�ֵj��j�ķ�ΧΪ0~��������͵�һ��
 * ת�Ʒ���Ҳ�ͺ���⣬��j��������λ��i��������鿴dp[i-1][j] �� dp[i-1][j-nums[i]]
 * ��С�ڣ���ֻ�鿴dp[i-1][j]
 * */

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = 0;
        for (auto val : nums) {
            sum += val;
        }
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};
