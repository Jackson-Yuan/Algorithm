/**
 * Give you the width and height of the rectangle,darw it.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, m;
    while (cin >> m >> n) {
        for (int i = 0; i < n + 2; ++i) {
            if (i == 0 || i == n + 1) cout << "+";
            else cout << "|";
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n + 1) cout << "-";
                else cout << " ";
            }

            if (i == 0 || i == n + 1) cout << "+";
            else cout << "|";

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}