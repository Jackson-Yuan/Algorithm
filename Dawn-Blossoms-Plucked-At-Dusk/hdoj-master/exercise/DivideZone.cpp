/**
 * 我们看到过很多直线分割平面的题目，
 * 今天的这个题目稍微有些变化，我们要求的是n条折线分割平面的最大数目。
 * 比如，一条折线可以将平面分成两部分，两条折线最多可以将平面分成7部分，
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
        int sum;
        cin >> sum;
        vector<int> res;
        res.push_back(0);
        res.push_back(2);
        res.push_back(7);
        for (int i = 3; i <= sum; ++i) {
            int tmp = res[i - 1] + 4 * i - 3;
            res.push_back(tmp);
        }

        cout << res[sum] << endl;
    }

    return 0;
}
/**
 * 此题是折线，不妨先看波直线的递推
 * 要使n条直线划分的区域做多，低n条就要与前n-1条相交且
 * 交点不能一样，这样n-1个交点在第n条直线上加上前n-1条
 * 可以新增n个区域
 *
 * 同理若直线换为折线前n-1个折线有2*（n-1）条边，相当于第n条
 * 折线每条边被2*（n-1）直线相交 则一条边生成2n-1条边
 * 两条4n-2，但由于折线，有个区域是公共区域，得减掉 所以为
 * 4n-3
 * */