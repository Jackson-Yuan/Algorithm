#include<stdio.h>
#include<math.h>

int main() {
    int n, x, i, j, flag, flag_1, m = 0, y = 0;
    scanf("%d", &n);
    while (n--) {
        flag = 0;
        scanf("%d", &x);
        if (x == 0) {
            printf("2 2\n");
            continue;
        }
        if (x == 1) {
            printf("2 1\n");
            continue;
        }
        if (x == 2) {
            printf("%d 0\n", x);
            continue;
        }
        for (i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d 0\n", x);
            continue;
        } else {
            y = x - 1;
            while (y) {
                flag_1 = 0;
                for (i = 2; i <= sqrt(y); i++) {
                    if (y % i == 0) {
                        flag_1 = 1;
                        break;
                    }
                }
                if (flag_1 == 0) {
                    m = y;
                    break;
                }
                y = y - 1;
            }
            y = x + 1;

            while (y) {
                flag_1 = 0;
                for (i = 2; i <= sqrt(y); i++) {
                    if (y % i == 0) {
                        flag_1 = 1;
                        break;
                    }
                }
                if (flag_1 == 0) {
                    j = y;
                    break;
                }
                y = y + 1;
            }
            if ((x - m) > (j - x)) {
                printf("%d %d\n", j, j - x);
            }
            if ((x - m) < (j - x)) {
                printf("%d %d\n", m, x - m);
            }
            if ((x - m) == (j - x)) {
                printf("%d %d\n", m, x - m);
            }
        }


    }
}
