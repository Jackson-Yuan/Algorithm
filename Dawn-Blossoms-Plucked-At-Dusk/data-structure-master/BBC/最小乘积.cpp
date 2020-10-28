#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int a[10];
int b[10];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n, cmp);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] * b[i];
        }
        cout << sum << endl;
    }

}
/**
此题无话可说 两个数组 求相同下标乘积之和为最小 
本来想着两个数组从小到大一波排掉 发现有负数会打破这个规律 慌了
其实 举个例子 a数组为 c,d d > c  b数组也为 c,d d>c 
从小到大的话 为  c^2 + d ^2  逆序排的话为2dc  前者大于等于后者 佛了 
*/
