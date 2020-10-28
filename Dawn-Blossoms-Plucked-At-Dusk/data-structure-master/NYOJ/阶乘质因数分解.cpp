#include<stdio.h>

int main() {
    int m, n, j, i, temp, sum, x;
    scanf("%d", &j);
    while (j--) {
        scanf("%d %d", &n, &m);
        sum = 0;
        for (temp = n; temp >= m; temp--) {
            x = temp;
            for (i = 2; i <= x; i++) {
                while (x != i) {
                    if ((x % i) == 0) {
                        if (i == m) sum++;
                        x = x / i;
                    } else
                        break;
                }
            }
            if (x == m) sum++;
        }
        printf("%d\n", sum);
    }

}
