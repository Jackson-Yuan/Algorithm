#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int flag = 0;
        for (int i = 0; i <= a; i++) {
            if (i * 2 + 4 * (a - i) == b) {
                printf("%d %d\n", i, a - i);
                flag = 1;
            }

        }
        if (flag != 1)
            printf("No answer\n");
    }
}
