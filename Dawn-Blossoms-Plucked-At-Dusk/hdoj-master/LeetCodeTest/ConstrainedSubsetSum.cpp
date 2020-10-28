/**
 * 给你一个整数数组nums和一个整数k，请你返回非空子序列元素和的最大值，
 * 子序列需要满足：子序列中每两个相邻的整数nums[i]和nums[j] ，它们在原数组中的下标 i 和 j 满足 i < j 且 j - i <= k 。
 * 数组的子序列定义为：将数组中的若干个数字删除（可以删除 0 个数字），剩下的数字按照原本的顺序排布。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int> &nums, int k) {
        int ans = INT_MIN;
        deque<int> q;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            dp[i] = max(nums[i], (q.empty() ? 0 : dp[q.front()]) + nums[i]);
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    /**int constrainedSubsetSum(vector<int>& nums, int k) {
          for(int i = 0 ; i < nums.size() ; ++i){
              dp[i] = nums[i];
          }

          for(int i = 1 ; i < nums.size() ; ++i){
              int j = i - 1;
              while(j >= 0 && i - j <= k){
                  dp[i] = max(dp[i], dp[j] + nums[i]);
                  --j;
              }
          }

          int maxValue = dp[0];
          for(int i = 1 ; i < nums.size() ; ++i){
              if(dp[i] > maxValue) maxValue = dp[i];
          }

          return maxValue;
      }*/
};
/**
 * 本题本质上是最大连续子串和的变体，变化在于可以不连续，i - j <= k
 * 注释部分是超时代码,若k很大,直接超时
 * 优化方法为利用双端队列模拟一个单调队列,队列中递减排列,且队列元素个数根据 i - j <= k来维护
 * 每次dp转移时时,直接取队头索引的dp值,代表在前k个元素的最大值,队列为空就默认0
 * 然后再将本次dp的值与队列里的元素进行比较,比他小的直接弹出,随和自己压入队尾
 * */