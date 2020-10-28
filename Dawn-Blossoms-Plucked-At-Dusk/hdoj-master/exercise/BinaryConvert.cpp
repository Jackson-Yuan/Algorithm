/**
 * 输入一个十进制数N，将它转换成R进制数输出。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, r;
    while (cin >> n >> r) {
        string res = "";
        bool token = true;
        if (n < 0) {
            n = -n;
            token = false;
        }

        while (n) {
            int tmp = n % r;
            if (tmp < 10) {
                res.append(1, '0' + tmp);
            } else {
                res.append(1, 'A' + tmp - 10);
            }

            n /= r;
        }

        if (!token) res.append(1, '-');

        reverse(res.begin(), res.end());

        cout << res << endl;
    }

    return 0;
}