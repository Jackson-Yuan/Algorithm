/**
 * 寒假的时候，ACBOY要去拜访很多朋友，恰巧他所有朋友的家都处在坐标平面的X轴上。
 * ACBOY可以任意选择一个朋友的家开始访问，但是每次访问后他都必须回到出发点，然后才能去访问下一个朋友。
 * 比如有4个朋友，对应的X轴坐标分别为1， 2， 3， 4。当ACBOY选择坐标为2的点做为出发点时，则他最终需要的时间为 |1-2|+|2-2|+|3-2|+|4-2| = 4。
 * 现在给出Ｎ个朋友的坐标，那么ACBOY应该怎么走才会花费时间最少呢？
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

int getRealVal(int val) {
    return val >= 0 ? val : -val;
}

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int sum;
        cin >> sum;
        vector<int> location;
        for (int i = 0; i < sum; ++i) {
            int tmp;
            cin >> tmp;
            location.push_back(tmp);
        }

        sort(location.begin(), location.end());
        int start = location[(location.size() - 1) / 2];
        int res = 0;
        for (int i = 0; i < location.size(); ++i) {
            res += getRealVal(start - location[i]);
        }

        cout << res << endl;
    }

    return 0;
}

/**
 * 此题出发点必须选取一个朋友家，最初误以为是取朋友家所包含区间的中点，
 * 其实只要去朋友家坐标在中间的即可
 * */