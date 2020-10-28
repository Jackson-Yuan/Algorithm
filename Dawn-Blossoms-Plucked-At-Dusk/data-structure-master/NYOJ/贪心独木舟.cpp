#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[300];
    while (n--) {
        int max, m;
        scanf("%d %d", &max, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        int start = 0, count = 0;
        int end = m - 1;
        while (start <= end) {
            if (a[start] + a[end] <= max) {
                start++;
                end--;
            } else end--;
            count++;
        }
        printf("%d\n", count);
    }
}
