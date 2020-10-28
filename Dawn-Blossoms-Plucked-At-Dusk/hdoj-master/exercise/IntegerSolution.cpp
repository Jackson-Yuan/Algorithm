/**
 * 有二个整数，它们加起来等于某个整数，乘起来又等于另一个整数，
 * 它们到底是真还是假，也就是这种整数到底存不存在，实在有点吃不准，你能快速回答吗？看来只能通过编程。
 * 例如：
 * x + y = 9，x * y = 15 ? 找不到这样的整数x和y
 * 1+4=5，1*4=4，所以，加起来等于5，乘起来等于4的二个整数为1和4
 * 7+(-8)=-1，7*（-8）=-56，所以，加起来等于-1，乘起来等于-56的二个整数为7和-8
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
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        int pre = n * n - 4 * m;
        if (pre < 0) {
            cout << "No" << endl;
            continue;
        }
        int judge = (int) sqrt(pre);
        if (judge * judge != n * n - 4 * m) {
            cout << "No" << endl;
            continue;
        }

        if ((n + judge) % 2 == 0 && (n - judge) % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
/**
 * 此题翻译一下就是求一元二次方程是否有整数解的问题
 * 还是不够灵活 草
 * */