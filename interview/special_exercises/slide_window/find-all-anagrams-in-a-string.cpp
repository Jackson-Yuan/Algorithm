#include "iostream"
#include "vector"
#include "map"

using namespace std;

/**
 * 给定两个字符串s和p，找到s中所有p的异位词的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string
 * */

/**
 * 本题思路，根据异位词的特性，我们可以维护一个长度为p字符串长度的滑动窗口，每次向右移动
 * 并同步增删窗口中个不同字符的数量（用map保存）
 * */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        map<char, int> m;
        for (char val : p) {
            ++m[val];
        }

        int start = 0;
        for (int i = 0; i < p.length(); ++i) {
            if (m.find(s[i]) != m.end()) {
                --m[s[i]];
            }
        }

        if (check(m)) {
            ans.push_back(start);
        }

        for (int i = p.length(); i < s.length(); ++i) {
            ++start;
            if (m.find(s[start - 1]) != m.end()) {
                ++m[s[start - 1]];
            }

            if (m.find(s[i]) != m.end()) {
                --m[s[i]];
            }

            if (check(m)) {
                ans.push_back(start);
            }
        }

        return ans;
    }

    bool check(map<char, int> &m) {
        bool flag = true;

        auto ite = m.begin();

        while (ite != m.end()) {
            if (ite->second != 0) {
                flag = false;
                break;
            }

            ++ite;
        }

        return flag;
    }


};

