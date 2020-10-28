#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int a[10000];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (a[0] == 1) {
            a[1]++;
            a[0] = 0;
        }
        if (a[n - 1] == 1) {
            a[n - 2]++;
            a[n - 1] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == 0) continue;
            if (a[i] == 1) {
                int left = i - 1;
                int right = i + 1;
                while (a[left] == 0) left--;
                while (a[right] == 0) right++;
                if (a[left] == 2) a[left]++;
                else if (a[left] <= a[right]) a[left]++;
                else a[right]++;
                a[i] = 0;
            }
        }
        int sum = 1;
        for (int i = 0; i < n; i++) {
            if (a[i]) sum = (sum * a[i]) % 10086;
        }
        printf("%d\n", sum);
    }
}
/*此题大致思路是找到1 并将它讨论向左加还是向右加 (仔细想想是这么个道理 除了1 其他数肯定是全部相乘来的大)，并把本为置0(题目还是要慢慢想啊 真特么草了 )
关键一点来了 有2的情况还要优先结合 理由如下 如 a < b 则 (a+1)b > a(b+1) 所以 找到left与right 时 优先加最小的 但对2 却很特殊  比2小的 只有1  但不能加到1上
因为 本题处理的就是1 其他数均不处理 就是讨论1的加法 如果单纯的把1加上另外一个1等于把1变成2(浪费了另外一个1的加的机会)  但如果直接给2 则会变3 另外一个1再加个另外一个值 会使值更大
另外 判断条件一定是小于等于，道理前见 1 2 1 3 1 4 类似于 a < b 则 (a+1)b > a(b+1) 比如开始时 是 3 1 3 1 4 如果没有等号则会给第二个3 变成 3 4 1 4 再来 3 4 5
如果有等号 则会是 4 3 1 4 最后4 4 4 (是个规律 旁边两数相等 优先加左边的 想到这个的我也是服) 
*/
