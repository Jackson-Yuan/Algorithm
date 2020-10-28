#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>

double a[600];
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n);

        double length = 20.0;
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= 1) continue;
            if (length >= 0) {
                double temp = sqrt(a[i] * a[i] - 1.0) * 2;
                length -= temp;
                count++;
            }
        }
        printf("%d\n", count);
    }
}
/*
没啥好说的 贪心思想 尽量都选覆盖范围大的 同时 这个范围 要晓得喷水装置的有效面积覆盖范围
但注意 数据是双精度型 输入必须要用lf 否则双精度型变量无法接受 不能是f 否则报错 
但printf函数却%f %lf输出double型均可 
*/
