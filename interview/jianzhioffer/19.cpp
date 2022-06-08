#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include "set"
#include "stack"

using namespace std;

/**
 * 正则匹配 就离谱
 * */
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }


    bool match(string &s, int s_index, string &p, int p_index) {
        if (s_index < s.length() && p_index < p.length()) {
            if (p_index + 1 < p.length() && p[p_index + 1] == '*') {
                if (s[s_index] == p[p_index] || p[p_index] == '.')
                    return match(s, s_index + 1, p, p_index) || match(s, s_index, p, p_index + 2) ||
                           match(s, s_index + 1, p, p_index + 2);
                else return match(s, s_index, p, p_index + 2);
            } else if (p[p_index] == '.') return match(s, s_index + 1, p, p_index + 1);
            else {
                if (s[s_index] == p[p_index]) return match(s, s_index + 1, p, p_index + 1);
                else return false;
            }

        } else if (s_index == s.length() && p_index == p.length()) return true;
        else {
            if (s_index == s.length()) {
                if (p_index + 1 < p.length() && p[p_index + 1] == '*') {
                    return match(s, s_index, p, p_index + 2);
                } else return false;
            } else return false;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.isMatch("", "");
}