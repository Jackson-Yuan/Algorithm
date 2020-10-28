/**
 * 算法笔记 p215
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

bool judge(int val) {
    if (val <= 1) return false;
    int end = (int) sqrt(val);
    for (int i = 2; i <= end; ++i) {
        if (val % i == 0) return false;
    }

    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    while (!judge(m)) ++m;
    map<int, bool> mm;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if (!mm[cur % m]) {
            cout << cur % m;
            mm[cur % m] = true;
        } else {
            int start = cur % m;
            bool token = false;
            int ite = 1;
            while (ite) {
                int index = start + ite * ite;
                if (index % m == start) break;/**如果探测的位置再一次回到原点，则证明已经不可能有地方插入了，或者终止循环的条件改为探测次数
 * 小于散列表长*/
                if (!mm[index % m]) {
                    cout << index % m;
                    token = true;
                    mm[index % m] = true;
                    break;
                } else {
                    ++ite;
                }
            }

            if (!token) cout << "-";
        }

        if (i != n - 1) cout << " ";
    }

    return 0;
}