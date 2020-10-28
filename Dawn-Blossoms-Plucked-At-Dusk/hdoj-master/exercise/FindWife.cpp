/**
 * 首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;
 * 然后,让各位新郎寻找自己的新娘.每人只准找一个,并且不允许多人找一个.
 * 最后,揭开盖头,如果找错了对象就要当众跪搓衣板...
 * 看来做新郎也不是容易的事情...
 * 假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

long long getSum(int start, int count) {
    long long sum = 1;
    while (count--) {
        sum *= start;
        --start;
    }

    return sum;
}

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m, k;
        cin >> m >> k;
        long long count = getSum(m, k) / getSum(k, k);
        vector<long long> res;
        res.push_back(0);
        res.push_back(0);
        res.push_back(1);
        for (int i = 3; i <= k; ++i) {
            long long tmp = (i - 1) * res[i - 1] + (i - 1) * res[i - 2];
            res.push_back(tmp);
        }

        cout << count * res[k] << endl;
    }

    return 0;
}