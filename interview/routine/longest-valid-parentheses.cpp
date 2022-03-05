#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

/**
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 链接:https://leetcode-cn.com/problems/longest-valid-parentheses/
 * */

/**
 * 我们可以利用栈来判断一个括号串是否匹配。此题可以以类似思路，利用栈来解决
 * 具体思路为，利用栈来保存索引而非实际存储的符号。
 * 栈顶部保存匹配字符串序列的前一个位置的索引（方便右括号索直接减去得到长度，这也是一开始为何要压入-1的原因）
 * */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxVal = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxVal = max(maxVal, i - st.top());
                }
            }
        }

        return maxVal;
    }
};
