/**
 * 字符串的算术表达式，算出结果
 * 三个栈，注意栈的判空(利用||与&&的短路机制)
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
        stack<char> number, character;
        map<char, int> prior;
        prior['+'] = 0;
        prior['-'] = 0;
        prior['*'] = 1;
        prior['/'] = 1;
        prior['('] = 2;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                number.push(str[i]);
            } else if (str[i] == ')') {
                while (character.top() != '(') {
                    number.push(character.top());
                    character.pop();
                }
                character.pop();
            } else {
                if (character.empty() || prior[str[i]] >= prior[character.top()]) character.push(str[i]);
                else {
                    while (!character.empty() && prior[str[i]] < prior[character.top()]) {
                        if (character.top() == '(') break;/**遇到左括号不弹出，括号优先级高*/
                        number.push(character.top());
                        character.pop();
                    }

                    character.push(str[i]);
                }
            }
        }

        while (!character.empty()) {
            number.push(character.top());
            character.pop();
        }

        string target;
        while (!number.empty()) {
            target.append(1, number.top());
            number.pop();
        }

        reverse(target.begin(), target.end());
        stack<int> res;
        for (int i = 0; i < target.length(); ++i) {
            if (target[i] >= '0' && target[i] <= '9') {
                res.push(target[i] - '0');
            } else {
                int b = res.top();
                res.pop();
                int a = res.top();
                res.pop();
                int tmpRes;

                if (target[i] == '+') tmpRes = a + b;
                else if (target[i] == '-') tmpRes = a - b;
                else if (target[i] == '*') tmpRes = a * b;
                else tmpRes = a / b;

                res.push(tmpRes);

            }
        }

        cout << res.top() << endl;
    }

    return 0;
}