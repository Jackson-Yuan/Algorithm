#include "iostream"
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;

/**
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 链接：https://leetcode.cn/problems/word-break
 * */

/**
 * 本题的最初想法，dfs暴力+剪枝（下面的dfs方法），但依然超时无解
 * 利用动态规划的想法，dp数组的意义为s串前i个长度的串是否匹配
 *
 * 状态转移的原则为，判断前i个位置是否匹配，遍历j（即起点）[0,i-1]
 * 首先查看d[j]是否匹配，匹配的话，查看[j,i-1]组成的字符串在dict里面
 * 是否能找到，找到直接为true，并判断i之后的位置
 *
 * */
class Solution {
private:
    bool isFind;
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        auto wordDictSet = unordered_set<string>();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }

    void dfs(vector<string> &wordDict, string &s, string cur) {
        if (s.substr(0, cur.length()) != cur) return;
        if (cur.length() > s.length()) return;

        if (s.length() == cur.length()) {
            isFind = true;
            return;
        }

        for (auto &word: wordDict) {
            if (!isFind) {
                dfs(wordDict, s, cur + word);
            }
        }
    }
};