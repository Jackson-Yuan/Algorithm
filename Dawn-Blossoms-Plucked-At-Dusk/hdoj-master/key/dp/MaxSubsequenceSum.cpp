/**
 * 算法笔记 p387
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
    vector<int> array(n);
    bool token = false;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] >= 0) {
            token = true;
        }
    }
    if (!token) {
        cout << 0 << " " << array[0] << " " << array[n - 1] << endl;
        return 0;
    }
    vector<int> dp(n);
    vector<int> start(n);
    dp[0] = array[0];
    start[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (array[i] > dp[i - 1] + array[i]) {
            start[i] = i;
            dp[i] = array[i];
        } else {
            start[i] = start[i - 1];
            dp[i] = array[i] + dp[i - 1];
        }
    }

    int max = dp[0], resLeft = start[0], resRight = 0;
    for (int i = 1; i < n; ++i) {
        if (max < dp[i]) {
            max = dp[i];
            resLeft = start[i];
            resRight = i;
        }
    }

    cout << max << " " << array[resLeft] << " " << array[resRight] << endl;
    return 0;
}
/**
 * dp 最大和玩花样
 * */