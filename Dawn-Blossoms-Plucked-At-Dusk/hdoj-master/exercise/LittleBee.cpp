/**
 * 有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
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
        int start, end;
        cin >> start >> end;

        vector<long long> res;
        res.push_back(1);
        for (int i = start + 1; i <= end; ++i) {
            long long tmp = 0;
            if (i - 2 >= start) tmp += res[i - 2 - start];
            tmp += res[i - 1 - start];
            res.push_back(tmp);
        }

        cout << res[res.size() - 1] << endl;
    }

    return 0;
}