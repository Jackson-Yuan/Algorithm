/**
 * 给定一个字符串，字符串含有括号，在未能匹配的括号上标注，左括号$ 右括号？
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        stack<int> s;
        string res(str.length(), ' ');
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                s.push(i);
            } else if (str[i] == ')') {
                if (!s.empty()) s.pop();
                else res[i] = '?';
            }
        }

        while (!s.empty()) {
            res[s.top()] = '$';
            s.pop();
        }

        cout << str << endl << res << endl;
    }

    return 0;
}