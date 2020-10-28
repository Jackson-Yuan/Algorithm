/**
 * 杭州人称那些傻乎乎粘嗒嗒的人为62（音：laoer）。
 * 杭州交通管理局经常会扩充一些的士车牌照，新近出来一个好消息，以后上牌照，不再含有不吉利的数字了，
 * 这样一来，就可以消除个别的士司机和乘客的心理障碍，更安全地服务大众。
 * 不吉利的数字为所有含有4或62的号码。例如：
 * 62315 73418 88914
 * 都属于不吉利号码。但是，61152虽然含有6和2，但不是62连号，所以不属于不吉利数字之列。
 * 你的任务是，对于每次给出的一个牌照区间号，推断出交管局今次又要实际上给多少辆新的士车上牌照了。
 * */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

bool judge(int val) {
    int after = -1;
    while (val) {
        int tmp = val % 10;
        if (tmp == 4) return false;
        else if (tmp == 6 && after == 2) return false;
        else if (tmp == 2) after = 2;

        if (tmp != 2) after = -1;
        val /= 10;

    }


    return true;
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        int count = 0;
        for (int i = n; i <= m; ++i) {
            if (judge(i)) ++count;
        }

        cout << count << endl;
    }

    return 0;
}