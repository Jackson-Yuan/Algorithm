/**
 * “回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int start = 0, end = str.length() - 1;
        bool token = true;
        while (start < end) {
            if (str[start] != str[end]) {
                token = false;
                break;
            }
            ++start;
            --end;
        }

        if (token) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}