#include "iostream"
#include "vector"

using namespace std;

/**
 * Ä¿²âÒª±³
 * */
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> weightArr(n + 1);
    vector<int> valueArr(n + 1);

    vector<vector<int>> dp(n + 1, vector<int>(c + 1));

    for (int i = 1; i <= n; ++i) {
        cin >> weightArr[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> valueArr[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (j >= weightArr[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weightArr[i]] + valueArr[i]);
            } else dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][c];
}