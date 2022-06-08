#include "iostream"
#include "string"
#include "map"

using namespace std;

/**
 * 最长不含重复字符的子串
 * 依然利用分解小问题子问题，用动态规划来做，步骤如下：
 * 从第一个字符开始计数，开始遍历。若遍历中出现一个字符（如在位置j）在之前出现过
 * 计算与重复字符之间的距离d，则先看j-1位置的以此位置为结束的最长不重复子串是多长。
 * 若d大于它则说明不在我们考虑的范围内，j-1位置的长度直接赋值给j，若小于等于，则代表
 * 重复字符出现在以此j-1位置为结束的最长不重复子串中，则j位置的的长度为d。
 * 每遍历一个点，进行最大值的判断
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        map<char, int> m;
        int ans = -1;
        int cur = 0;
        for (int i = 0; i < s.length(); ++i) {
            auto ite = m.find(s[i]);

            if (ite == m.end()) {
                ++cur;
            } else {
                int d = i - ite->second;
                if (d <= cur) cur = d;
                else ++cur;
            }

            m[s[i]] = i;
            if (cur > ans) ans = cur;
        }

        return ans;
    }
};

