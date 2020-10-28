#include<stdio.h>

/*²ð5ºÍ2*/
int a[10][10];

int main() {
    int n;
    int m;
    int max = 0;
    int min = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            while (a[i][j] % 5 == 0) {
                max++;
                a[i][j] = a[i][j] / 5;
            }
            while (a[i][j] % 2 == 0) {
                min++;
                a[i][j] = a[i][j] / 2;
            }
        }
    }

    if (max > min) printf("%d\n", min);
    else printf("%d\n", max);
}
