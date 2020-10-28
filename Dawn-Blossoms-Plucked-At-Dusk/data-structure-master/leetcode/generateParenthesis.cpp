
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> start(1, "");
        vector<vector<string>> all(n + 1, start);

        for (int i = 1; i <= n; i++) {
            vector<string> tmp;
            for (int j = 0; j < i; ++j) {
                vector<string> part1 = all[j];
                vector<string> part2 = all[i - 1 - j];

                for (int k = 0; k < part1.size(); ++k) {
                    for (int m = 0; m < part2.size(); ++m) {
                        string target = "(" + part1[k] + ")" + part2[m];
                        tmp.push_back(target);
                    }
                }
            }

            all[i] = tmp;
        }

        return all[n];
    }
};

/**
 * 此题一种较为暴力的解法，是暴力搜索n对括号的所有排列情况，再用栈判断是否配对
 * 上面所示的是动态规划的方法
 * all[i]表说i对括号的结果，因为答案成立的每个结果肯定是以'('开始，')'的位置不定
 * 所以dp[i] = '(' + dp[j] +　')' + dp[i-1-j] (i > j)
 * 十分流弊
 * */