#include "iostream"
#include "set"
#include "vector"

using namespace std;


/**
 * 输入一串字符串，求组合而非排列
 *
 * */
class Solution {
private:
    set<string> ans;
    vector<bool> visited;
public:
    vector<string> permutation(string s, int n) {
        return dfs(s, n);
    }

    vector<string> dfs(string &target, int n) {
        vector<string> ans;
        if (n == 0 || target.length() == 0 || target.length() < n) return ans;

        if (n == 1) {
            for (char val : target) {
                string cur = "";
                ans.push_back(cur.append(1, val));
            }

            return ans;
        } else {
            string head = target.substr(0, 1);
            string next_string = target.substr(1);
            vector<string> one = dfs(next_string, n - 1);
            vector<string> two = dfs(next_string, n);
            for (string val : one) ans.push_back(head + val);
            for (string val : two) ans.push_back(val);

            return ans;

        }
    }
};

int main() {
    Solution solution;

    vector<string> ans = solution.permutation("abcde", 3);

    for (string val : ans) {
        cout << val << endl;
    }
}