#include<stdio.h>
#include<math.h>

int main() {
    float a[600];
    int n, m;
    scanf("%d", &m);
    while (m--) {
        float sum = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%f", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] < a[j]) {
                    float temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            sum = sum + 2 * sqrt(a[i] * a[i] - 1);
            if (sum >= 20) {
                printf("%d\n", i + 1);
                break;
            }
        }

    }
    return 0;
}
