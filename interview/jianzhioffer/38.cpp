#include "iostream"
#include "string"
#include "set"
#include "vector"

using namespace std;


/**
 * set用于去重 比如求aab这三个字母全排列
 * 不去重会重复
 * */
class Solution {
private:
    set<string> ans;
    vector<bool> visited;
public:
    vector<string> permutation(string s) {
        vector<string> res;
        if (s.length() == 0) return res;
        visited = vector<bool>(26, false);
        ans.clear();
        dfs(0, "", s);


        auto ite = ans.begin();
        while (ite != ans.end()) {
            res.push_back(*ite);
            ++ite;
        }
        return res;
    }

    void dfs(int index, string target, string &s) {
        if (index == s.length()) {
            ans.insert(target);
            return;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(index + 1, target.append(1, s[i]), s);
                target.erase(target.length() - 1, 1);
                visited[i] = false;
            }
        }
    }
};

