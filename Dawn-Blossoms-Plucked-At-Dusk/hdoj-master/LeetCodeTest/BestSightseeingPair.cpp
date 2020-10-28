/**
 * 给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
 * 一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
 * 返回一对观光景点能取得的最高分。
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
    int maxScoreSightseeingPair(vector<int> &A) {
        int ans = INT_MIN, maxValue = A[0];
        for (int i = 1; i < A.size(); ++i) {
            ans = max(ans, maxValue + A[i] - i);
            maxValue = max(maxValue, A[i] + i);
        }
        return ans;
    }
};
/**
 * 换个角度看问题A[i] + A[j] + i - j 可看成 A[i] + i + A[j] - j
 * A[j] - j可在每次循环固定,只需计算0到j - 1间A[i] + i的最大值即可
 * 当然暴力也行,但超时
 * */