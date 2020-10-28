/**
 * 今年的ACM暑期集训队一共有18人，分为6支队伍。其中有一个叫做EOF的队伍，由04级的阿牛、XC以及05级的COY组成。在共同的集训生活中，大家建立了深厚的友谊，
 * 阿牛准备做点什么来纪念这段激情燃烧的岁月，想了一想，阿牛从家里拿来了一块上等的牛肉干，
 * 准备在上面刻下一个长度为n的只由"E" "O" "F"三种字符组成的字符串
 * （可以只有其中一种或两种字符，但绝对不能有其他字符）,阿牛同时禁止在串中出现O相邻的情况，
 * 他认为，"OO"看起来就像发怒的眼睛，效果不好。
 * 你，NEW ACMer,EOF的崇拜者，能帮阿牛算一下一共有多少种满足要求的不同的字符串吗？
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
    while (cin >> n) {
        vector<long long> res;
        res.push_back(3);
        long long last = 1;
        for (int i = 1; i < n; ++i) {
            long long tmp = 3 * res[i - 1] - last;
            last = res[i - 1] - last;
            res.push_back(tmp);
        }

        cout << res[n - 1] << endl;
    }

    return 0;
}