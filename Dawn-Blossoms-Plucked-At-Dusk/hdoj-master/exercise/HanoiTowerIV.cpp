/**
 * 还记得汉诺塔III吗？他的规则是这样的：不允许直接从最左(右)边移到最右(左)边(每次移动一定是移到中间杆或从中间移出)，
 * 也不允许大盘放到小盘的上面。xhd在想如果我们允许最大的盘子放到最上面会怎么样呢？（只允许最大的放在最上面）当然最后需要的结果是盘子从小到大排在最右边。
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
        vector<long long> res;
        res.push_back(2);
        for (int i = 1; i < sum; ++i) {
            long long tmp = res[i - 1] * 3 - 2;
            res.push_back(tmp);
        }

        cout << res[sum - 1] << endl;
    }

    return 0;
}
/**
 * 依然汉诺塔找规律
 * 虽然这个式子不晓得原理是啥
 * 但可以列几项直接看出规律
 * 但真正原理如下：
 * 求i个盘子的最小次数，应该先将i-1个盘子移动到中间，再将最大的移动两次到右边
 * 最后将中间的移动到右边即可
 * 所以问题就转化为如何求i个盘子移动到中间的次数
 * 这个很好解决，先将i-1个盘子移动到右边的次数，加上最大移动到中间，再将i-1个右边移到中间即可
 * 骚
 * */