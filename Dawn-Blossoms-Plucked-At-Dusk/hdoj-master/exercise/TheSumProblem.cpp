/**
 * Given a sequence 1,2,3,......N,
 * your job is to calculate all the possible sub-sequences that the sum of the sub-sequence is M.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

/*
int main(){
    int n, m;
    while (true){
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n ; ++i) {
            res[i] = res[i - 1] + i;
        }

        for (int i = 1; i <= n ; ++i) {
            for (int j = i - 1; j >= 0 ; --j) {
                int tmp = res[i] - res[j];
                if (tmp == m){
                    cout << "[" << j + 1 << "," << i << "]" << endl;
                } else if (tmp > m){
                    break;
                }
            }
        }

        cout << endl;
    }

    return 0;
}*/

int main() {
    long long n, m, a;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = sqrt(2 * m); i > 0; i--) {
            a = m / i - (i - 1) / 2;
            //需检查i是否为整数。
            if (a * i + i * (i - 1) / 2 == m)
                cout << '[' << a << ',' << a + i - 1 << ']' << endl;
        }
        cout << endl;
    }

    return 0;
}
/**
 * 此题注释掉方案采取暴力的方法解决，但给的数据过大，会内存超限
 * 这时可采用数学的方法：
 * 首先需要知道一个数学知识:

1+2+3+⋯+√2m>m
所以和为m的元素的个数最多不超过 √2m 个，最少有 1 个。

接下来就可以用for循环，通过序列元素的个数来进行计算。
而这个计算需要用到等差数列求和公式：

Sn=a1n+n(n−1)*d/2，n∈N∗
a1 为首项，n为项数，d为公差，那么求首项的变形公式为：
此公式逆推可解出首项
通过上式即可求出首项 a1a1，那么最后一项就是 a1+n−1a1+n−1，即 [a1,a1+n−1][a1,a1+n−1].

 * */