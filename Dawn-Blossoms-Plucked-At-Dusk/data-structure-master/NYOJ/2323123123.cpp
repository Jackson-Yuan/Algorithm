#include<stdio.h>

int sushu(int n) {
    if (n == 1 || n == 0) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int b[123], max, min;
    char a[100];
    char *p;
    for (int i = 0; i < 123; i++) {
        b[i] = 0;
    }
    int temp = 0;
    max = min = 0;
    scanf("%s", a);
    p = a;
    while (*p != '\0') {
        b[*p]++;
        p++;
    }
    for (int i = 0; i < 123; i++) {
        if (b[i] != 0) {
            max = b[i];
            min = b[i];
            break;
        }
    }
    for (int i = 0; i < 123; i++) {
        if (b[i] != 0) {
            if (max < b[i])
                max = b[i];
        }
    }
    for (int i = 0; i < 123; i++) {
        if (b[i] != 0) {
            if (min > b[i])
                min = b[i];
        }
    }
    temp = max - min;
    if (sushu(temp)) {
        printf("Lucky Word");
    } else printf("Unlucky Word");


}
