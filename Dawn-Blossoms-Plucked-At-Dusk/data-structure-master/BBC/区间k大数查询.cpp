#include<stdio.h>

int a[10001];
int result[10001];
int n;

void swim(int k) {
    while (k > 1) {
        int j = k / 2;
        if (result[j] < result[k]) {
            int temp = result[j];
            result[j] = result[k];
            result[k] = temp;
            k = j;
        } else break;
    }
}

void sink(int k) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j + 1 <= n && result[j + 1] > result[j]) j++;
        if (result[k] > result[j]) break;
        int temp = result[j];
        result[j] = result[k];
        result[k] = temp;
        k = j;
    }
}

void delMax() {
    result[1] = result[n];
    n--;
    sink(1);
}

void insert(int k) {
    n++;
    result[n] = k;
    swim(n);
}

int main() {
    int sum;
    scanf("%d", &sum);
    for (int i = 1; i <= sum; i++) {
        scanf("%d", &a[i]);
    }
    int count;
    int l, r, k;
    scanf("%d", &count);
    while (count--) {
        scanf("%d%d%d", &l, &r, &k);
        n = 0;
        for (int i = l; i <= r; i++) {
            insert(a[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            delMax();
        }
        printf("%d\n", result[1]);
    }
}
/*
此题可以直接截取数组排序 也可以使用优先队列来解决 降低时间复杂度
稳健 
*/
