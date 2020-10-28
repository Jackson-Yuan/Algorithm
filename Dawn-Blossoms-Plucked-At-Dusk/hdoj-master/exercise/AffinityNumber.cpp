/**
 * 古希腊数学家毕达哥拉斯在自然数研究中发现，220的所有真约数(即不是自身的约数)之和为：
 * 1+2+4+5+10+11+20+22+44+55+110＝284。
 * 而284的所有真约数为1、2、4、71、 142，加起来恰好为220。人们对这样的数感到很惊奇，
 * 并称之为亲和数。一般地讲，如果两个数中任何一个数都是另一个数的真约数之和，则这两个数就是亲和数。
 * 你的任务就编写一个程序，判断给定的两个数是否是亲和数
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
        int a, b;
        map<int, int> m;
        cin >> a >> b;
        int sum = 1;
        for (int i = 2; i < a; ++i) {
            if (a % i == 0) {
                sum += i;
            }
        }

        if (sum == b) {
            sum = 1;
            for (int i = 2; i < b; ++i) {
                if (b % i == 0) {
                    sum += i;
                }
            }

            if (sum == a) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}