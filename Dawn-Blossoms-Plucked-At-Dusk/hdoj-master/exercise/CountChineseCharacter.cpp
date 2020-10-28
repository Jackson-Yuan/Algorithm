/**
 * 统计给定文本文件中汉字的个数。
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
    int n;
    cin >> n;
    getchar();
    while (n--) {
        getline(cin, str);
        int count = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] < 32 || str[i] > 126) ++count;
        }

        cout << count / 2 << endl;
    }
}