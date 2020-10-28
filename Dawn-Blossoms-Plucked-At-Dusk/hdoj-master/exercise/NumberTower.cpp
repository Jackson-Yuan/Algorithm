/**
 * 见网页原题hdoj2084
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
    while (n--) {
        int step;
        cin >> step;
        vector<vector<int>> tower;
        for (int i = 0; i < step; ++i) {
            vector<int> res(i + 1, -1);
            for (int j = 0; j < res.size(); ++j) {
                cin >> res[j];
            }
            tower.push_back(res);
        }

        vector<vector<int>> ans;
        vector<int> res(1, tower[0][0]);
        ans.push_back(res);
        for (int i = 1; i < tower.size(); ++i) {
            vector<int> tmp(i + 1, 0);
            for (int j = 0; j < tmp.size(); ++j) {
                if (j - 1 >= 0 && tower[i][j] + ans[i - 1][j - 1] > tmp[j]) tmp[j] = tower[i][j] + ans[i - 1][j - 1];
                if (j < ans[i - 1].size() && tower[i][j] + ans[i - 1][j] > tmp[j]) tmp[j] = tower[i][j] + ans[i - 1][j];
            }

            ans.push_back(tmp);
        }

        int val = -1;
        for (int i = 0; i < ans[ans.size() - 1].size(); ++i) {
            if (ans[ans.size() - 1][i] > val) {
                val = ans[ans.size() - 1][i];
            }
        }

        cout << val << endl;
    }

    return 0;
}