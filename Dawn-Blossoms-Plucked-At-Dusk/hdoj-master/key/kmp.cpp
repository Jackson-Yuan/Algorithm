/**
 * kmp算法实现，利用AC自动机原理非next数组，略屌
 * https://zhuanlan.zhihu.com/p/83334559
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
vector<vector<int>> dp;

int main() {
    string str, target;
    while (cin >> str >> target) {
        dp = vector<vector<int>>(target.length(), vector<int>(256, 0));
        dp[0][target[0]] = 1;

        int x = 0;
        for (int i = 1; i < target.length(); ++i) {
            cout << i << " shadow is: " << x << endl;
            for (int j = 0; j < 256; ++j) {
                if (target[i] == j) {
                    dp[i][j] = i + 1;
                } else {
                    dp[i][j] = dp[x][j];
                }
            }

            x = dp[x][target[i]];
        }

        int index = 0;
        bool token = false;
        for (int i = 0; i < str.length(); ++i) {
            index = dp[index][str[i]];

            if (index == target.length()) {
                token = true;
                cout << i - target.length() + 1 << endl;
                break;
            }
        }


        if (!token) cout << "no matching" << endl;

    }

    return 0;
}