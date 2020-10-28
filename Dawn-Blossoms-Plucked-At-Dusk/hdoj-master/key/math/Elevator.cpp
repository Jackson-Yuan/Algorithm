/**
 *算法笔记 p196
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    int compare = 0;
    for (int i = 0; i < n; ++i) {
        int target;
        cin >> target;
        if (target >= compare) {
            res += (target - compare) * 6 + 5;
        } else {
            res += (compare - target) * 4 + 5;
        }

        compare = target;
    }
    cout << res << endl;
    return 0;
}