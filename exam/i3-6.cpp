#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n, INT_MAX);
    vector<vector<int>> dis(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cur;
            cin >> cur;
            dis[i][j] = cur;
            dis[j][i] = cur;
        }
    }

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + dis[j][i]);
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}