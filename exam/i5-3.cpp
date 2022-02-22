#include "iostream"
#include "vector"

using namespace std;
int n, m, d;
vector<int> ans;
vector<int> path;
vector<vector<int>> data;

void dfs(int index, int cost) {
    if (index == n) {
        if (ans.empty()) ans = path;
        else {
            int ansValue = 0, pathValue = 0;
            for (int i = 0; i < n; ++i) {
                ansValue += data[i + n][ans[i]];
                pathValue += data[i + n][path[i]];
            }

            if (ansValue > pathValue) ans = path;
        }
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (cost + data[index][i] <= d) {
            path.push_back(i);
            dfs(index + 1, cost + data[index][i]);
            path.pop_back();
        }
    }
}

int main() {
    cin >> n >> m >> d;
    data = vector<vector<int>>(2 * n, vector<int>(m));
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> data[i][j];
        }
    }

    dfs(0, 0);
    int res = 0;
    for (int i = 0; i < ans.size(); ++i) {
        res += data[i + n][ans[i]];
        cout << ans[i] + 1 << " ";
    }
    cout << endl << res;
}