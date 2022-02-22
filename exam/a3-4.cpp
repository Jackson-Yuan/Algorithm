#include "iostream"
#include "vector"

using namespace std;

struct good {
    int weight;
    int volume;
    int value;
};

int main() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(c + 1, vector<int>(d + 1, 0)));
    vector<good> goods(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> goods[i].weight >> goods[i].volume >> goods[i].value;
    }
    for (int i = 1; i <= n; ++i) {
        int weight = goods[i].weight, volume = goods[i].volume, value = goods[i].value;
        for (int j = 1; j <= c; ++j)
            for (int k = 1; k <= d; ++k) {
                if (j >= weight && k >= volume)
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - weight][k - volume] + value);
                else dp[i][j][k] = dp[i - 1][j][k];
            }
    }

    return dp[n][c][d];
}