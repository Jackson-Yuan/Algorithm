#include<stdio.h>

int main() {
    int n;
    int a[1000];
    scanf("%d", &n);
    while (n--) {
        int m;
        int sum = 0;
        scanf("%d", &m);
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

        while (m > 3) {
            if (2 * a[0] + a[m - 2] > 2 * a[1] + a[0]) sum = sum + 2 * a[1] + a[0] + a[m - 1];
            else sum = sum + 2 * a[0] + a[m - 2] + a[m - 1];
            m = m - 2;

        }
        if (m == 1) sum = sum + a[0];
        if (m == 2) sum = sum + a[1];
        if (m == 3) sum = sum + a[0] + a[1] + a[2];
        printf("%d\n", sum);
    }

}
