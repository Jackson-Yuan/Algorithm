#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int lowBit(int n) {
    return n - (n & (n - 1));
}

void update(int n, int i, int v, int *a) {
    for (int k = i; k <= n; k += lowBit(k)) {
        a[k] += v;
    }
}

int getSum(int *a, int i) {
    int sum = 0;
    for (int k = i; k >= 1; k -= lowBit(k)) {
        sum += a[k];
    }
    return sum;
}

int main() {
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int c[9];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 8; i++) {
        update(9, i + 1, a[i], c);
    }

    for (int i = 0; i < 9; i++) {
        cout << c[i] << " ";
    }
}
/**
树状数组用来解决区间和的问题
一般解法是例如有个数组a[11](0号位不放元素)
则维护一个数组c[11](0号位不放元素) c[i]表示前i个a数组元素之和大小 利用此方法在求区间和时可降低时间复杂度
但如果a数组更新 则c数组相应的也需要更新 时间复杂度为线性级别

树状数组则为这样
c1 = a1 
c2 = a1 + a2
c3 = a3
c4 = a1 + a2 + a3 + a4
c5 = a5
c6 = a5 + a6
以此类推
看出的规律为 c[i] 中必以ai为结尾  个数为2^k(k位i的二进制形式 从低位开始数0的个数，即末尾0的个数，也可以说是从末尾起 第一个1的位置所代表的十进制值) 可以定义一个方法lowbit(i)求出2^k 
如果a数组的某元素出现更新 如a[i]出现更新 则c[i]肯定要更新  c[i + lowbit(i)], c[i + lowbit(i) + lowbit(i + lowbit(i)) ]也要更新 复杂度变为对数级
若求前n个和 若求前i个的和 则为c[i] + c[i - lowbit(i)] + .....以此类推 索引值必须大于1 (0号为不做处理) 也为对数级
发现这规律的也挺屌的 
*/
