/**
 * hdoj 2159
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct monster {
    int cost;
    int experience;
};

int main() {
    int n, m, k, s;
    while (cin >> n >> m >> k >> s) {
        vector<vector<int>> dp(s + 1, vector<int>(m + 1, 0));
        vector<monster> monsters;
        for (int i = 0; i < k; ++i) {
            monster current;
            cin >> current.experience >> current.cost;
            monsters.push_back(current);
        }

        for (int i = 1; i <= s; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int l = 0; l <= m; ++l) {
                    if (l >= monsters[j].cost)
                        dp[i][l] = max(dp[i][l], dp[i - 1][l - monsters[j].cost] + monsters[j].experience);
                    else dp[i][l] = max(dp[i][l], dp[i - 1][l]);
                }
            }
        }

        bool token = false;
        for (int i = 0; i <= m; ++i) {
            if (dp[s][i] >= n) {
                token = true;
                cout << m - i;
                break;
            }
        }

        if (!token) {
            cout << -1;
        }

        cout << endl;


    }

    return 0;

}
/**
 * 此题也是背包问题的变体，具体一点就是是完全背包的变体
 * 虽然怪物可以无限杀，但特么杀怪总数不能超过10个
 * 设置dp数组时，采用二维，表达的含义是，杀i个怪物耐久度为j时的经验值
 * 其实某种程度上来说这个变体变成了0-1背包，个数是确定的，一次一个
 * 但这个一个是杀哪种还是需要递推比较一番的
 * */