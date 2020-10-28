/**
 * HDU 2006'10 ACM contest的颁奖晚会隆重开始了！
 * 为了活跃气氛，组织者举行了一个别开生面、奖品丰厚的抽奖活动，这个活动的具体要求是这样的：
 * 首先，所有参加晚会的人员都将一张写有自己名字的字条放入抽奖箱中；
 * 然后，待所有字条加入完毕，每人从箱中取一个字条；
 * 最后，如果取得的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
 * 大家可以想象一下当时的气氛之热烈，毕竟中奖者的奖品是大家梦寐以求的Twins签名照呀！不过，正如所有试图设计的喜剧往往以悲剧结尾，这次抽奖活动最后竟然没有一个人中奖！
 * 我的神、上帝以及老天爷呀，怎么会这样呢？
 * 不过，先不要激动，现在问题来了，你能计算一下发生这种情况的概率吗？
 * 不会算？难道你也想以悲剧结尾？！
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

long long getSum(int val) {
    long long sum = 1;
    for (int i = 0; i < val; ++i) {
        sum *= (i + 1);
    }

    return sum;
}

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int count;
        cin >> count;
        vector<long long> res;
        res.push_back(0);
        res.push_back(0);
        res.push_back(1);
        for (int i = 3; i <= count; ++i) {
            long long tmp = (i - 1) * res[i - 1] + (i - 1) * res[i - 2];
            res.push_back(tmp);
        }

        double tmp = getSum(count);
        double tmpp = 100.0 * res[count];
        printf("%.2lf", tmpp / tmp);
        cout << "%" << endl;
    }

    return 0;
}
/**
 * 此题一开始理解错误，其实就是这么个情况，总的抓取情况，比上一个都抓不对的情况，总的抓取情况没啥好说就是个阶乘
 * 一个都抓不对的情况是个递推式，可以这么理解设f(n)为当count为n时错误的抓取情况：
 * 当前n-1个人全部抓取失败时，第n个人可以与前面n-1个任意换位置
 * 当前n-1个人有一个抓取成功时，第n个人与这个人调换，这个人随便选一个即可，总个数：f(n-2)*(n-1);
 * 最后还有一个极其肯比的地方 double tmpp = 100.0 * res[count]; 这地方若tmpp依然是long long型
 * 不好意思count=20直接超范围
 * */