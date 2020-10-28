/**
问题描述
　　考虑一种简单的正则表达式：
　　只由 x ( ) | 组成的正则表达式。
　　小明想求出这个正则表达式能接受的最长字符串的长度。


　　例如 ((xx|xxx)x|(x|xx))xx 能接受的最长字符串是： xxxxxx，长度是6。
输入格式
　　一个由x()|组成的正则表达式。输入长度不超过100，保证合法。
输出格式
　　这个正则表达式能接受的最长字符串的长度。
样例输入
((xx|xxx)x|(x|xx))xx
样例输出
6
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>

using namespace std;

int main() {
    stack<string> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str.substr(i, 1) == ")") {
            string temp;
            while (s.top() != "(") {
                temp.append(s.top());
                s.pop();
            }
            s.pop();
            string pushStr;
            int start = 0, length;
            while (1) {
                int index, j;
                for (j = start; j < temp.length(); j++) {
                    if (temp[j] == '|') {
                        index = j;
                        length = j - start;
                        break;
                    }
                }
                if (j == temp.length()) {
                    length = temp.length() - start;
                }
                if (length > pushStr.length()) {
                    pushStr = temp.substr(start, length);
                }
                if (j == temp.length()) break;
                index++;
                start = index;
            }
            for (int j = 0; j < pushStr.length(); j++) {
                s.push(pushStr.substr(j, 1));
            }

        } else s.push(str.substr(i, 1));
    }
    string temp;
    while (!s.empty()) {
        temp.append(s.top());
        s.pop();
    }
    string pushStr;
    int start = 0, length;
    while (1) {
        int index, j;
        for (j = start; j < temp.length(); j++) {
            if (temp[j] == '|') {
                index = j;
                length = j - start;
                break;
            }
        }
        if (j == temp.length()) {
            length = temp.length() - start;
        }
        if (length > pushStr.length()) {
            pushStr = temp.substr(start, length);
        }
        if (j == temp.length()) break;
        index++;
        start = index;
    }
    int count = 0;
    for (int i = 0; i < pushStr.length(); i++) {
        if (pushStr[i] == 'x') count++;
    }
    cout << count << endl;
}
/**
利用栈可以解决带括号的问题  当然这题细节较多 
第一个循环时消除括号 第二个循环是在第一个循环消除括号内 '|'符的基础上 再消除残余的'|'符 
*/
