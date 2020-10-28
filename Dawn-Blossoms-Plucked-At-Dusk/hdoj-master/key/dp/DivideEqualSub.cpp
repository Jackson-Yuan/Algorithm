/**
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 注意:
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/**
class Solution {
private:
    vector<int> array;
    bool res;
    int target;
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        target = sum / 2;
        array = nums;
        res = false;
        dfs(0, 0);
        return res;
    }

    void dfs(int index, int sum){
        if(index == array.size()){
            if(sum == target) res = true;
            return;
        }
        if(!res && sum + array[index] <= target) dfs(index + 1, sum + array[index]);
        if(!res && sum <= target) dfs(index + 1, sum);
    }
};
 上面的代码所示是dfs暴力解法，配合剪枝可以过90/105个测试数据
 值得注意的是，若不加!res进行进一步剪枝(题目要求是找到，并没有指明找多少个)，只能过23个测试数据
 */
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() == 0) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];

        if (sum % 2 == 1) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));

        if (target >= nums[0]) dp[0][nums[0]] = true;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j == nums[i]) dp[i][j] = true;
                else if (j > nums[i]) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                else dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[nums.size() - 1][target];
    }
};

/**
 * 正确解法 依然是充满玄学的动态规划
 * dp[i][j]的定义为前i个数(并不一定都要选上去)组成目标值为j是否可以true or false
 * 先设置边界：
 * dp[0][nums[0]] if target >= nums[0] 其余全为false
 * 再看递推式
 * 若j正好为nums[i]，则dp[i][j]肯定为true
 * 若j > nums[i] 则看dp[i - 1][j] 与 dp[i - 1][j - nums[i]]是否有一个为true 有的话直接赋值
 * 否则 j < nums[i] 那么只能看dp[i - 1][j]的情况了
 * */
int main() {
    Solution solution;
    vector<int> array = {1, 5, 11, 5};
    solution.canPartition(array);
}
