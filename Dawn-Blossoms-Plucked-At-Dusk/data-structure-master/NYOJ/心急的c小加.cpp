#include<iostream>
#include<algorithm>

using namespace std;
struct wood {
    int length;
    int weight;
};

bool compare(struct wood a, struct wood b) {
    return a.length == b.length ? a.weight < b.weight : a.length < b.length;
}

struct wood a[1500];
int b[1500];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a[i].length >> a[i].weight;
        }
        sort(a, a + m, compare);

        int k = 0, j;
        b[k] = a[0].weight;
        for (int i = 1; i < m; i++) {
            for (j = 0; j <= k; j++) {
                if (a[i].weight >= b[j]) {
                    b[j] = a[i].weight;
                    break;
                }
            }
            if (j > k) {
                k++;
                b[k] = a[i].weight;
            }
        }
        cout << k + 1 << endl;
    }
    return 0;
}
/*
本题依然贪心思路，排序时注意思路，按长度排序，长度一样，按重量排序，必须这样，如果少了后者即长度一样，按weight排，否则会出现bug
求解循环中，也是值得注意的把weight放入数组中储存，因为长度是排序排好的，长度不需考虑，把凡是需新开一个单位时间的weight都保存起来
使剩下的木棍一一比较 
*/
