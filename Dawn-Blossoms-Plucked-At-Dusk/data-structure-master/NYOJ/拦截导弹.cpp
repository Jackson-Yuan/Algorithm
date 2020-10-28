#include<stdio.h>

int main() {
    int a[20];
    int b[20];
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            b[i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] < a[j] && b[i] < b[j] + 1) {
                    b[i] = b[j] + 1;
                }
            }
        }
        int max = b[0];
        for (int i = 0; i < m; i++) {
            if (max < b[i]) {
                max = b[i];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
