/**
 * 输入一个英文句子，将每个单词的第一个字母改成大写字母。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        str[0] -= 32;
        for (int i = 1; i < str.length(); ++i) {
            if (str[i] == ' ') {
                str[i + 1] -= 32;
                ++i;
            }
        }

        cout << str << endl;
    }

    return 0;
}