#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

int diff(string x, string y, int i, int j) {
    return x[i] == y[j] ? 0 : abs(x[i] - y[j]);
}

int main() {
    string str1, str2;
    int k;
    cin >> str1 >> str2;
    cin >> k;
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    for (int i = 1; i <= str1.length(); ++i) {
        dp[i][0] = k * i;
    }

    for (int i = 1; i <= str2.length(); ++i) {
        dp[0][i] = k * i;
    }

    for (int i = 1; i <= str1.length(); ++i) {
        for (int j = 1; j <= str2.length(); ++j) {
            dp[i][j] = min(dp[i - 1][j] + k, min(dp[i][j - 1] + k, dp[i - 1][j - 1] + diff(str1, str2, i - 1, j - 1)));
        }
    }

    cout << dp[str1.length()][str2.length()];
    return 0;
}