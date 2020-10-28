/**
 * 有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，
 * 如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
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
    while (cin >> n >> m) {
        int start = 2, count = 0, sum = 0;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if ((i % m == 0 && count != 0)) {
                int tmp = sum / count;
                res.push_back(tmp);
                sum = 0;
                count = 0;
            }
            ++count;
            sum += start;
            start += 2;

            /**最后到末尾不足m个进行判断*/
            if (i == n - 1) {
                res.push_back(sum / count);
            }
        }


        for (int j = 0; j < res.size(); ++j) {
            cout << res[j];
            if (j != res.size() - 1) cout << " ";
        }

        cout << endl;
    }

    return 0;
}