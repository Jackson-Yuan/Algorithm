#include<stdio.h>

int main() {
    int a;
    int n;
    int b[7], index;
    scanf("%d", &n);
    while (n--) {
        int i;
        index = 0;
        scanf("%d", &a);
        if (a < 0) a = -a;
        while (a) {
            b[index++] = a % 10;
            a = a / 10;
        }
        index--;
        for (i = index - 1; b[i] == 0; i--) {
            if (i == 0) break;
        }
        if (i == 0) printf("%d\n", b[i]);
        else {
            for (int j = i; j >= 0; j--) {
                printf("%d", b[j]);
            }
            printf("\n");
        }

    }
    return 0;
}
