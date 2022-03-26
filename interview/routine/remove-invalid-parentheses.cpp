#include "iostream"
#include "vector"
#include "string"
#include "set"

using namespace std;

/**
 * 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。
 * 返回所有可能的结果。答案可以按 任意顺序 返回。
 * */

/**
 * 首先通过遍历字符串统计需要最小删减的左括号数右括号数
 *
 * 然后开始暴力深搜
 *
 * 注意这个题的深搜方式，有难度
 * 通过删减某个括号，加上左右串进入下个状态进行深搜
 * 同时，剪枝操作值得留意
 * */
class Solution {
private:
    set<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftCount = 0, rightCount = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++leftCount;
            } else if (s[i] == ')') {
                ++rightCount;
                if (leftCount > 0) {
                    --leftCount;
                    --rightCount;
                }
            }
        }

        vector<string> res;

        ans.clear();
        dfs(s, 0, leftCount, rightCount);
        auto ite = ans.begin();
        while (ite != ans.end()) {
            res.push_back(*ite);
            ++ite;
        }
        return res;
    }


    void dfs(string &s, int start, int leftCount, int rightCount) {
        if (leftCount == 0 && rightCount == 0) {
            if (isValid(s)) {
                ans.insert(s);
            }

            return;
        }


        for (int i = start; i < s.length(); ++i) {

            if (leftCount + rightCount > s.length() - i) return;

            if (leftCount > 0 && s[i] == '(') {
                string cur = s.substr(0, i) + s.substr(i + 1);
                dfs(cur, i, leftCount - 1, rightCount);
            }

            if (rightCount > 0 && s[i] == ')') {
                string cur = s.substr(0, i) + s.substr(i + 1);
                dfs(cur, i, leftCount, rightCount - 1);
            }
        }
    }


    bool isValid(string &cur) {
        int leftCount = 0, rightCount = 0;

        for (int i = 0; i < cur.length(); ++i) {
            if (cur[i] == '(') {
                ++leftCount;
            } else if (cur[i] == ')') {
                ++rightCount;
                if (leftCount > 0) {
                    --leftCount;
                    --rightCount;
                } else return false;
            }
        }

        return leftCount == 0 && rightCount == 0;
    }

};