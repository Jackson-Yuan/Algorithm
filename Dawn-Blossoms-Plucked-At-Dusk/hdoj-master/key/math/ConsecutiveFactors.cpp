/**
 * 算法笔记 p218
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main() {
    int n;
    int res = 0;
    vector<int> resArray;
    cin >> n;
    int end = (int) sqrt(n) + 1;
    for (int i = 2; i <= end; ++i) {
        long long sum = 1;
        int start = i;
        vector<int> path;
        while (true) {
            path.push_back(start);
            sum *= start;
            if (n % sum == 0 && path.size() > res) {
                res = path.size();
                resArray = path;
            }
            if (sum > n) break;
            ++start;
        }
    }


    if (res == 0) {
        cout << 1 << endl;
        cout << n << endl;
    } else {
        cout << res << endl;
        for (int i = 0; i < resArray.size(); ++i) {
            cout << resArray[i];
            if (i != resArray.size() - 1) cout << "*";
            else cout << endl;
        }
    }
    return 0;
}
/**
 * 此题一个循环终止条件根号n
 * 但原理不是太懂，且res = 0时还需要特殊处理
 * 推荐无脑暴力枚举起点就完事了
 * */