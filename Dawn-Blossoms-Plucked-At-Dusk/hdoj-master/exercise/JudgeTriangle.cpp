/**
 * 给定三条边，请你判断一下能不能组成一个三角形。
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
        double len[3];
        for (int i = 0; i < 3; ++i) {
            cin >> len[i];
        }

        if (len[1] + len[0] <= len[2]) {
            cout << "NO" << endl;
            continue;
        }

        if (len[0] + len[2] <= len[1]) {
            cout << "NO" << endl;
            continue;
        }

        if (len[1] + len[2] <= len[0]) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}