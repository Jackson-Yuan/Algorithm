#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[1001];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + m);

        int sum = 0;
        while (m >= 4) {
            if (2 * a[1] + a[0] + a[m - 1] <= 2 * a[0] + a[m - 1] + a[m - 2]) {
                sum += 2 * a[1] + a[0] + a[m - 1];
            } else sum += 2 * a[0] + a[m - 1] + a[m - 2];

            m -= 2;
        }
        if (m == 1 || m == 2) {
            sum += a[m - 1];
        } else if (m == 3) {
            sum += a[m - 1] + a[m - 2] + a[m - 3];
        }

        printf("%d\n", sum);
    }
}
/*
此题 有两种策略  一个是 最短和和第二短先过河 最短送手电筒回来 然后最长和第二长过河 第二短送手电筒回来 以此为轮回
第二个策略是 让最短的一个个送 再一次次回来 以此为轮回 每次轮回都要将这两种策略比较
究其原因 两种策略的表达式为 a[1]+a[1]+a[0]+a[m-1]与a[0]+a[0]+a[m-1]+a[m-2]
约掉相同的 则剩下 a[1]+a[1] 与 啊a[0]+a[m-2]这两个进行比较 
*/
