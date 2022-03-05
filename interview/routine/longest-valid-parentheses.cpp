#include "iostream"
#include "vector"
#include "string"
#include "stack"

using namespace std;

/**
 * ����һ��ֻ���� '(' �� ')' ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�
 * ����:https://leetcode-cn.com/problems/longest-valid-parentheses/
 * */

/**
 * ���ǿ�������ջ���ж�һ�����Ŵ��Ƿ�ƥ�䡣�������������˼·������ջ�����
 * ����˼·Ϊ������ջ��������������ʵ�ʴ洢�ķ��š�
 * ջ��������ƥ���ַ������е�ǰһ��λ�õ�������������������ֱ�Ӽ�ȥ�õ����ȣ���Ҳ��һ��ʼΪ��Ҫѹ��-1��ԭ��
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
