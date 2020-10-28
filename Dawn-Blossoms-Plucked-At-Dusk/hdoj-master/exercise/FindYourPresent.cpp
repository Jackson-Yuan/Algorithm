/**
 * 在新年晚会上，每个人都会得到一份“特别礼物”。现在该轮到您拿起特别礼物了，现在有很多礼物放在桌子上，只有一个是您的。
 * 每个礼物都有卡号。在上面，您的礼物卡号将是一个与其他号码不同的数字，您可以假设只有一个数字出现奇数次。
 * 例如，有5个礼物，它们的卡号是1、2、3， 2，1.因此您的礼物将是卡号为3的礼物，因为3是与其他号码不同的号码。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

/**int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;
            ++m[val];
        }
        int res;
        auto ite = m.begin();
        while (ite != m.end()) {
            if (ite->second % 2 == 1) {
                res = ite->first;
                break;
            }
            ++ite;
        }
        cout << res << endl;
    }

    return 0;
}*/
int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        int val, ans;
        scanf("%d", &val);
        ans = val;
        for (int i = 1; i < n; ++i) {
            scanf("%d", &val);
            ans ^= val;
        }

        cout << ans << endl;
    }
    return 0;
}
/**
 * 本题用注释代码直接超时
 * 可以使用异或
 * 一个数与本身异或是0，与0异或是本身
 * 所以因为只有一个数是奇数个，其余的数全是偶数个
 * 那么所有偶数个数的数异或结果0，再奇数个数的数异或正好是其本身
 * 6逼
 * */