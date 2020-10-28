/**
 *一个为1-n的集合，其子集按字典顺序排列，求第m个
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        vector<long long> data(n + 1, 0);
        data[1] = 1;
        for (int i = 2; i <= n; ++i) {
            data[i] = data[i - 1] * i + i;
        }
        vector<bool> vis(n + 1, false);
        vector<int> res;
        int realN = (int) n;

        while (m > 0) {
            --m;
            long long compare = (data[n] / n);
            long long token = m / compare;
            ++token;
            /**在未被选取的数中选第token个*/
            vector<int> path;
            for (int i = 1; i <= realN; ++i) {
                if (!vis[i]) {
                    path.push_back(i);
                }
            }
            token = path[token - 1];

            res.push_back((int) token);
            vis[token] = true;
            m = m % compare;
            --n;
        }


        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i != res.size() - 1) cout << " ";
        }

        cout << endl;
    }

    return 0;
}
/**
 * 此题举例找规律 例如n为3
 * 1        2         3
 * 1 2      2 1       3 1
 * 1 2 3    2 1 3     3 1 2
 * 1 3      2 3       3 2
 * 1 3 2    2 3 1     3 2 1
 *
 * 可以先找出n之间的规律，n的组合数为n-1的组合数乘以n再加n
 * 然后利用m/每组个数（n的组合数除以n）
 * 求出第一位为多少（m先自减1，然后按0开始算，算出来的值随后还原）
 * 接着m在对每组个数取模，恰恰等于n-1中每组个数的第m个，进行循环即可
 * (同时注意，每次选取的值选完之后要标记是访问)
 * */