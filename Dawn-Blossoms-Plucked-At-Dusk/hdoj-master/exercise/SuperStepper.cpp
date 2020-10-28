/**
 * 有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
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
        int target;
        cin >> target;
        vector<int> res(target, 0);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i < target; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }

        cout << res[target - 1] << endl;
    }

    return 0;
}