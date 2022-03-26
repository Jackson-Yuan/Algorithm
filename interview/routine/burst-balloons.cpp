#include "iostream"
#include "vector"

using namespace std;

/**
 * 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组nums中。
 * 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。这里的 i - 1 和 i + 1 代表和i相邻的两个气球的序号。
 * 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
 * 求所能获得硬币的最大数量。
 * 链接：https://leetcode-cn.com/problems/burst-balloons
 * */


/**
 * 本题首先按照题意 相邻数相乘，然后删掉中间的数，在计算某个香玲数，再删以此类推，找出和最大的选项
 * 这样算一个删一个会导致两个气球从不相邻变成相邻，使得后续操作难以处理，我们不如逆向思维，将全过程看作是每次添加一个气球
 * dfs(i,j)代表从i到j的最大值
 * 利用记忆化递归，保存历史遍历到的状态，以防重复计算
 *
 * 至于记忆化递归如何想到并使用，主要首先定义的递归意义，再按照递归树看是否出现重复的递归状态，如果出现重复，便可以使用记忆化递归
 *
 * 通常记忆化递归（自顶向下）可用动态规划（自底向上）改写
 * */
class Solution {
private:
    vector<vector<int>> state;
    vector<int> val;
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
        }

        val[0] = val[n + 1] = 1;

        state.resize(n + 2, vector<int>(n + 2, -1));
        return dfs(0, n + 1);
    }


    int dfs(int left, int right) {
        if (left + 1 >= right) return 0;

        if (state[left][right] != -1) return state[left][right];


        for (int i = left + 1; i < right; ++i) {
            int sum = val[left] * val[i] * val[right];
            sum += dfs(left, i) + dfs(i, right);
            state[left][right] = max(state[left][right], sum);
        }

        return state[left][right];
    }
};


/**
 * 动态规划写法
 * */
class Solution2 {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};


int main() {
    vector<int> nums = {3, 1, 5, 8};

    Solution solution;

    cout << solution.maxCoins(nums);
}

