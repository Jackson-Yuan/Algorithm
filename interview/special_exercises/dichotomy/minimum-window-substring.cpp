#include "iostream"
#include "string"
#include "map"
#include "unordered_map"

using namespace std;
/**
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
 * 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 注意：
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 链接：https://leetcode.cn/problems/minimum-window-substring
 * */

/**
 * 依然双指针，依靠两个map，一个记录t串拥有的字符及其字符数，一个记录当前区间包含t的字符及其个数
 * 思路具体见代码，大致为写一个判断函数，判断当前【left，right】是否可以覆盖t串
 * 若满足，尝试将left前移（因为要尽可能小），并进行相应字符个数减少
 * 若不满足，right前移
 *
 * 一些细节看代码注释
 * */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> flag, count;

        for (char cur: t) {
            ++flag[cur];
        }

        int left = 0, right = -1;
        int ansLeft = 0, ansRight = s.length();

        /**
         * s.length()返回的是无符号数，跟负数比，铁定不成立
         * */
        while (right < (int) s.length()) {
            if (check(flag, count)) {
                if (right - left < ansRight - ansLeft) {
                    ansLeft = left;
                    ansRight = right;
                }

                if (count.find(s[left]) != count.end()) --count[s[left]];
                ++left;
            } else {
                /**
                 * right初值必须为-1，然后先自增再判断
                 * 这样可以保证，right指向区间的最后一个字符而非区间最后一个字符的后一个字符
                 *
                 * 并且如果right处初值为0，先判断后自增
                 * 那么right指向区间的最后一个字符而非区间最后一个字符的后一个字符，
                 * 如果答案包含了s串最后一个字符，那么right就指向s.length()，直接退出循环
                 * 没有判断的机会
                 * */
                ++right;
                if (flag.find(s[right]) != flag.end()) ++count[s[right]];

            }
        }

        int len = ansRight - ansLeft + 1;
        if (ansRight == s.length()) return "";
        else return s.substr(ansLeft, len);
    }


    bool check(unordered_map<char, int> &flag, unordered_map<char, int> &count) {
        auto ite = flag.begin();

        while (ite != flag.end()) {
            if (count.find(ite->first) == count.end()) return false;
            if (count[ite->first] < ite->second) return false;
            ++ite;
        }

        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.minWindow("ADOBECODEBANC", "ABC");
}