/**
 * 多项式的描述如下：
 * 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
 * 现在请你求出该多项式的前n项的和。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int count;
    cin >> count;
    vector<double> res;
    while (count--) {
        int n;
        cin >> n;
        double sum = 0;
        for (int i = 1; i <= n; ++i) {
            double value = (double) 1 / i;/** notice*/
            if (i % 2 == 0) value = -value;

            sum += value;
        }

        res.push_back(sum);
    }

    for (int j = 0; j < res.size(); ++j) {
        printf("%.2f\n", res[j]);
    }

    return 0;
}