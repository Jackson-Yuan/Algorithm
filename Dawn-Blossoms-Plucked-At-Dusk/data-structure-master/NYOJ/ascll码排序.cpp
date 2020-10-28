#include<stdio.h>

int main() {
    int n, t, i, j;
    char a[3];
    scanf("%d", &n);

    while (n) {
        getchar();//读取回车 ，清空回车符
        scanf("%c %c %c", &a[0], &a[1], &a[2]);
        for (i = 0; i < 3; i++) {
            for (j = i + 1; j < 3; j++) {
                if (a[i] > a[j]) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
        for (i = 0; i < 3; i++) {
            printf("%c ", a[i]);
        }
        printf("\n");
        n--;
    }


} 
