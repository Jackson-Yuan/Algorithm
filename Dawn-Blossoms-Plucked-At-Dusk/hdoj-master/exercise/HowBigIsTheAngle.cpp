/**
 *时间过的好快，一个学期就这么的过去了，xhd在傻傻的看着表，出于对数据的渴望，突然他想知道这个表的时针和分针的夹角是多少。
 * 现在xhd知道的只有时间，请你帮他算出这个夹角。
 * 注：夹角的范围[0，180]，时针和分针的转动是连续而不是离散的。
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
    int c;
    double h, m, s, ans;
    cin >> c;
    while (c--) {

        cin >> h >> m >> s;
        if (h >= 12) h -= 12.0;
        m = m + s / 60.0;
        h = h + m / 60.0;
        ans = fabs(h * 30.0 - m * 6.0);
        printf("%d\n", (int) min(ans, 360.00 - ans));
    }
}
/**
 * 思路其实很容易，我反正想复杂了
 * 其实就是时针到12点所成的角度减去分针到12点所成的角度的绝度值而已
 * 同时注意，int强转不会出现四舍五入，而保留几位小数，会四舍五入
 * */