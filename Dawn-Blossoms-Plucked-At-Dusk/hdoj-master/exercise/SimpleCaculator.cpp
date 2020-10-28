/**
 * hdoj 1237
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stack>

using namespace std;

int strToDouble(string str) {
    int res = 0;
    for (int i = 0; i < str.length(); ++i) {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "0") break;
        map<char, int> priority;
        priority['+'] = priority['-'] = 0;
        priority['*'] = priority['/'] = 1;
        stack<string> target;
        stack<char> character;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') continue;
            if (str[i] >= '0' && str[i] <= '9') {
                int end = i;
                while (end < str.length() && str[end] != ' ') ++end;
                string cur = str.substr(i, end - i);
                target.push(cur);
                i = end;
            } else {
                if (character.empty() || priority[str[i]] > priority[character.top()]) character.push(str[i]);
                else {
                    while (!character.empty() && priority[str[i]] <= priority[character.top()]) {
                        char val = character.top();
                        string cur(1, val);
                        target.push(cur);
                        character.pop();
                    }
                    character.push(str[i]);
                }
            }
        }

        while (!character.empty()) {
            char val = character.top();
            string cur(1, val);
            target.push(cur);
            character.pop();
        }

        vector<string> res;
        while (!target.empty()) {
            res.push_back(target.top());
            target.pop();
        }

        reverse(res.begin(), res.end());
        stack<double> val;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i][0] >= '0' && res[i][0] <= '9') {
                double value = (double) strToDouble(res[i]);
                val.push(value);
            } else {
                double a = val.top();
                val.pop();
                double b = val.top();
                val.pop();
                double tmpRes;

                if (res[i] == "+") tmpRes = a + b;
                else if (res[i] == "-") tmpRes = b - a;
                else if (res[i] == "*") tmpRes = a * b;
                else tmpRes = b / a;

                val.push(tmpRes);
            }
        }

        printf("%.2lf\n", val.top());
    }
    return 0;
}