/**
 * 今年暑假杭电ACM集训队第一次组成女生队,其中有一队叫RPG,但做为集训队成员之一的野骆驼竟然不知道RPG三个人具体是谁谁。R
 * PG给他机会让他猜猜，第一次猜：R是公主，P是草儿，G是月野兔；第二次猜：
 * R是草儿，P是月野兔，G是公主；第三次猜：R是草儿，P是公主，G是月野兔；......可怜的野骆驼第六次终于把RPG分清楚了。由于RPG的带动，做ACM的女生越来越多，
 * 我们的野骆驼想都知道她们，可现在有N多人，他要猜的次数可就多了，为了不为难野骆驼，女生们只要求他答对一半或以上就算过关，请问有多少组答案能使他顺利过关。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

long long getSum(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

long long selectByM(int n, int m) {
    if (m < (n - m)) m = n - m;
    long long res = 1;
    for (int i = m + 1; i <= n; ++i) {
        res *= i;
    }
    for (int i = 1; i <= n - m; ++i) {
        res /= i;
    }

    return res;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<long long> data(n + 1, 0);
        data[2] = 1;
        for (int i = 3; i <= n; ++i) {
            data[i] = (i - 1) * (data[i - 1] + data[i - 2]);
        }


        long long sum = getSum(n);
        long long divide = 0;
        for (int j = n; j > n / 2; --j) {
            divide += selectByM(n, j) * data[j];
        }

        cout << sum - divide << endl;

    }

    return 0;
}
/**
 * 本题思路如下：
 * 选取m个数的组合个数 * m个数的错排数
 * 因为要求至少一半
 * 可以反过来想，先算出大于一半的错排数，接着拿总数减掉
 *
 * 当然算C(n, m)时存在无解坑点，不做处理，直接溢出
 * 可以借助C(n, m) = C(n, n - m)来优化 服
 * */