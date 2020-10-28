#include<stdio.h>

int main() {
    int a[1000];
    int k, n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        a[i] = -1;
    }
    int count;
    while (k) {
        count = 0;
        for (int i = 0; i < n; i++) {
            count++;
            if (count % k == 0) {
                a[i] = -a[i];
            }
        }
        k--;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            printf("%d ", i + 1);
    }
} 
