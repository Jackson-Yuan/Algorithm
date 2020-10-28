/**
 * 对于给定的一个字符串，统计其中数字字符出现的次数。
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
        int count = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') ++count;
        }

        cout << count << endl;
    }

    return 0;
}