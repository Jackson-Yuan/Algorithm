/**
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }

    void dfs(string str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        if (left > right) return;/**当左括号剩余个数大于右括号时，可以进行剪枝，因为这样肯定是不会成立的*/
        string tmp;
        if (left > 0) {
            tmp = str;
            tmp.append(1, '(');
            dfs(tmp, left - 1, right);
        }

        if (right > 0) {
            tmp = str;
            tmp.append(1, ')');
            dfs(tmp, left, right - 1);
        }


    }
};
/**
 * 此题就是利用dfs进行暴力搜索，留意一下剪枝操作，比较巧妙
 * 同时还有动态规划方法，但那个太骚，学不来
 * */