/**
 * 春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：
 *“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。
 * 现在要求输出所有在m和n范围内的水仙花数。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

bool judge(int value) {
    int a[3];
    int tmp = value;
    int index = 0;
    while (tmp) {
        a[index] = tmp % 10;
        ++index;
        tmp /= 10;
    }

    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += (a[i] * a[i] * a[i]);
    }

    return sum == value;
}

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<int> res;/**新的循环 清空数组*/
        bool token = false;
        for (int i = m; i <= n; ++i) {
            if (judge(i)) {
                token = true;
                res.push_back(i);
            }
        }

        if (!token) {
            cout << "no";
        } else {
            for (int i = 0; i < res.size(); ++i) {/**去除末尾空格，否则报输出格式错误*/
                cout << res[i];
                if (i != res.size() - 1) cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}