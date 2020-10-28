/**
 * 算法笔记 p396
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
int coins[10001];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int len, sum;
    cin >> len >> sum;
    for (int i = 0; i < len; ++i) {
        cin >> coins[i];
    }
    sort(coins, coins + len, cmp);/**转为倒序，这样遍历完正好为字典序最小的结果*/
    vector<vector<int>> dp(sum + 1);
    for (int i = 0; i < len; ++i) {
        for (int j = sum; j >= coins[i]; --j) {
            if (!dp[j - coins[i]].empty() || (j - coins[i] == 0)) {
                /**若j - coins[i] 可以拼凑及dp数组不为空 或 j - coins[i] 恰好为0 装入此硬币*/
                dp[j] = dp[j - coins[i]];
                dp[j].push_back(coins[i]);
            }
        }
    }

    if (dp[sum].empty()) {
        cout << "No Solution";
    } else {
        for (int i = dp[sum].size() - 1; i >= 0; --i) {
            cout << dp[sum][i];
            if (i != 0) cout << " ";
        }
    }

    cout << endl;
    return 0;
}
/**
 * 此问题用注释代码部分，dfs + 剪枝依然有两个样例无法过
 * 正确做法利用01背包来验证正确性
 * */
/**
int num[1000];
int len, sum;
bool isStop;
vector<int> path, res;

void dfs(int index, int all) {
    if (index == len) {
        if (all == sum) {
            res = path;
            isStop = true;
        }
        return;
    }
    if (all > sum) return;
    if (!isStop) {
        path.push_back(num[index]);
        dfs(index + 1, all + num[index]);
        path.pop_back();
        dfs(index + 1, all);
    }

}

int main() {
    cin >> len >> sum;
    for (int i = 0; i < len; ++i) {
        cin >> num[i];
    }

    sort(num, num + len);
    isStop = false;
    dfs(0, 0);
    if (!res.empty()) {
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i != res.size() - 1) cout << " ";
        }
    } else cout << "No Solution";

    cout << endl;
    return 0;

}*/