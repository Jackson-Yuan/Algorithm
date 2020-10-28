/**
 * 统计每个元音字母在字符串中出现的次数。
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
    getchar();/*防止getline读取回车，getline读取一行，遇到回车停止，但也会把回车读掉，但不会出现在读的内容里*/
    while (n--) {
        string str;
        map<char, int> m;
        getline(cin, str);
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ++m[str[i]];
        }

        string target = "aeiou";
        for (int j = 0; j < target.length(); ++j) {
            cout << target[j] << ":" << m[target[j]] << endl;
        }

        if (n != 0) cout << endl;

    }

    return 0;
}