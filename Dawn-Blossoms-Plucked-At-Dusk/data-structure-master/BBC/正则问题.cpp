/**
��������
��������һ�ּ򵥵�������ʽ��
����ֻ�� x ( ) | ��ɵ�������ʽ��
����С����������������ʽ�ܽ��ܵ���ַ����ĳ��ȡ�


�������� ((xx|xxx)x|(x|xx))xx �ܽ��ܵ���ַ����ǣ� xxxxxx��������6��
�����ʽ
����һ����x()|��ɵ�������ʽ�����볤�Ȳ�����100����֤�Ϸ���
�����ʽ
�������������ʽ�ܽ��ܵ���ַ����ĳ��ȡ�
��������
((xx|xxx)x|(x|xx))xx
�������
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
����ջ���Խ�������ŵ�����  ��Ȼ����ϸ�ڽ϶� 
��һ��ѭ��ʱ�������� �ڶ���ѭ�����ڵ�һ��ѭ������������ '|'���Ļ����� �����������'|'�� 
*/
