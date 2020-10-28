/**
 * 杨辉三角
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
    while (cin >> n) {
        vector<vector<int>> matrix(n, vector<int>(n, 1));

        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                cout << matrix[i][j];
                if (j != i) cout << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
    return 0;
}