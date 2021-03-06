/**
 * 约19世纪末，在欧州的商店中出售一种智力玩具，在一块铜板上有三根杆，最左边的杆上自上而下、由小到大顺序串着由64个圆盘构成的塔。
 * 目的是将最左边杆上的盘全部移到右边的杆上，条件是一次只能移动一个盘，且不允许大盘放在小盘的上面。
 * 现在我们改变游戏的玩法，不允许直接从最左(右)边移到最右(左)边(每次移动一定是移到中间杆或从中间移出)，也不允许大盘放到下盘的上面。
 * Daisy已经做过原来的汉诺塔问题和汉诺塔II，但碰到这个问题时，她想了很久都不能解决，现在请你帮助她。现在有N个圆盘，她至少多少次移动才能把这些圆盘从最左边移到最右边？
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
        vector<long long> res(n, 0);
        res[0] = 2;
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * 3 + 2;
        }

        cout << res[n - 1] << endl;
    }

    return 0;
}
/**
 * 依然找规律的题
 * 状态转移使解析如下：
 * 边界n=1时为2
 * n=2时，先要将最除底部以外的圆盘移到最右边，次数为res[n-1]
 * 然后再将底部移到中间，这时要将最右边的移至最左边，因为中间最大圆盘，不影响移动（可有可无）
 * 从右到做与从左到右的移动次数是一致的位res[n-1]，然后再将中间的移至最右边，然后此时情况等价于将n-1个移至最左边
 * 再算一次res[n-1]。即总计三次res[n-1]，外加两次移动最大圆盘
 * */