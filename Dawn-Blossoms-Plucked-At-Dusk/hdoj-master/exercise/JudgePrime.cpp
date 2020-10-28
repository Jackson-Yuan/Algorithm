/**
 * 对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

bool judge(int value) {
    for (int i = 2; i <= sqrt(value); ++i) {
        if (value % i == 0) return false;
    }

    return true;
}

int main() {
    int x, y;
    while (true) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        bool token = true;
        for (int i = x; i <= y; ++i) {
            int value = i * i + i + 41;
            if (!judge(value)) {
                token = false;
                break;
            }
        }

        if (token) cout << "OK" << endl;
        else cout << "Sorry" << endl;
    }

    return 0;
}