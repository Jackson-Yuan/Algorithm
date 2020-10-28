/**
 * 算法笔记 p198
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int judge(int val) {
    int count = 0;
    while (val) {
        if (val % 10 == 1) ++count;
        val /= 10;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += judge(i);
    }

    cout << res << endl;
    return 0;
}