/**
 * 对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”。
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

    while (cin >> str) {
        char max = str[0];

        for (int i = 1; i < str.length(); ++i) {
            if (str[i] > max) max = str[i];
        }

        for (int j = 0; j < str.length(); ++j) {
            if (str[j] == max) {
                str.insert(j + 1, "(max)");
                j += 5;
            }

            if (j == str.length() - 1) break;
        }

        cout << str << endl;
    }

    return 0;
}