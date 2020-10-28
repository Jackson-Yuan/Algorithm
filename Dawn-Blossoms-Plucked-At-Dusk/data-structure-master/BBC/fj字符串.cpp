#include<stdio.h>

void showStr(int n) {
    if (n == 1) {
        printf("A");
        return;
    } else {
        showStr(n - 1);
        printf("%c", 'A' + n - 1);
        showStr(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    showStr(n);;
    printf("\n");
}
