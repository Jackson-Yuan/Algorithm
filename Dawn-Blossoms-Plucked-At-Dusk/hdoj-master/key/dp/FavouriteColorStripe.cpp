/**
 * 算法笔记 p390
 * */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
int originalArray[10001];
int priority[201] = {0};

int main() {
    int all;
    cin >> all;
    int favourite, original;
    cin >> favourite;
    for (int i = 0; i < favourite; ++i) {
        int tmp;
        cin >> tmp;
        priority[tmp] = i + 1;
    }
    cin >> original;

    vector<int> dp(original, 0);
    for (int i = 0; i < original; ++i) {
        cin >> originalArray[i];
        if (priority[originalArray[i]] != 0) dp[i] = 1;
    }

    for (int i = 1; i < original; ++i) {
        if (priority[originalArray[i]] == 0) {
            dp[i] = dp[i - 1];
            continue;
        }
        for (int j = 0; j < i; ++j) {
            if (priority[originalArray[j]] != 0 && priority[originalArray[i]] >= priority[originalArray[j]]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxValue = -1;
    for (int i = 0; i < dp.size(); ++i) {
        if (maxValue < dp[i]) maxValue = dp[i];
    }

    cout << maxValue << endl;
    return 0;
}
/**
 * 此题是利用原生数组进行求解
 * 也可将喜欢的颜色提取出来生成一个数组，然后再利用LLS模板秒杀之
 * */