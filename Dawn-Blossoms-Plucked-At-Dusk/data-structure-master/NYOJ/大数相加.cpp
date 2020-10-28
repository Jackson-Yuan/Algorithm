#include<stdio.h>
#include<string.h>

int main() {
    char a[100];
    char b[100];
    int aa[100] = {0}, bb[100] = {0};
    int alen, blen, max;
    scanf("%s", a);
    getchar();
    scanf("%s", b);
    alen = strlen(a);
    blen = strlen(b);
    max = alen > blen ? alen : blen;
    int j = 0;
    for (int i = alen - 1; i >= 0; i--) {
        aa[j] = a[i] - '0';
        j++;
    }
    j = 0;
    for (int i = blen - 1; i >= 0; i--) {
        bb[j] = b[i] - '0';
        j++;
    }
    for (int i = 0; i < max; i++) {
        aa[i] = aa[i] + bb[i];
        if (aa[i] > 9) {
            aa[i] = aa[i] - 10;
            aa[i + 1]++;
        }
    }
    for (int i = max - 1; i >= 0; i--) {
        printf("%d", aa[i]);
    }
}
