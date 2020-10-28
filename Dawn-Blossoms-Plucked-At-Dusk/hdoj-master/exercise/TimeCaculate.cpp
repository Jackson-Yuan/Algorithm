/**
 * 时间加减
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int h1, m1, s1, h2, m2, s2;
    int n;
    cin >> n;
    while (n--) {
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        int resH, resM, resS;
        int extra = 0;
        resS = (s1 + s2) % 60;
        extra = (s1 + s2) / 60;
        resM = (m1 + m2 + extra) % 60;
        extra = (m1 + m2 + extra) / 60;
        resH = h1 + h2 + extra;
        cout << resH << " " << resM << " " << resS << endl;
    }

    return 0;
}