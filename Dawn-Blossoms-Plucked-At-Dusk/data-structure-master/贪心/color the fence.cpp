#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[9];
int n;

int findMin(int *a) {
    int min = 100001;
    int index = -1;
    for (int i = 0; i < 9; i++) {
        if (a[i] < min) {
            min = a[i];
            index = i;
        }
    }
    return min;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < 9; i++) {
            scanf("%d", &a[i]);
        }
        int min = findMin(a);
        if (min > n) {
            printf("-1\n");
            continue;
        }
        int count = n / min;
        while (count--) {
            for (int i = 8; i >= 0; i--) {
                if (n >= a[i] && (n - a[i]) / min == count) {
                    printf("%d", i + 1);
                    n -= a[i];
                    break;
                }
            }
        }
        printf("\n");
    }

}
/*此题就是找到耗费的最小值 求出最大能写几位数 这是大前提 然后在大前提下 尽量使每位数都尽可能大(这点没注意 以为是只要找到最小值就行 真是草了)
在搜索最大的数时 手法注意一下 判断数时 看看与这个数的差值 除以最小值能否 填满剩余的位置 不能就不行
毕竟位数多 肯定大 
*/ 
