#include "iostream"
#include "vector"

using namespace std;
int n;
vector<vector<int>> data;
vector<bool> visited;
int ans;

void dfs(int index, int val) {
    if (index == n) {
        if (val > ans) {
            ans = val;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(index + 1, val + data[index][i] * data[i + n][index]);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    data = vector<vector<int>>(2 * n, vector<int>(n));
    visited = vector<bool>(n, false);
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> data[i][j];
        }
    }
    ans = INT_MIN;
    dfs(0, 0);
    cout << ans << endl;
}