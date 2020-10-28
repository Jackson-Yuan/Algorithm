#include<stdio.h>
#include<string.h>

int main() {
    char a[1000];
    int n;
    while (scanf("%d", &n) != EOF) {

        gets(a);
        int len = strlen(a);
        int temp;
        for (int i = 0; i < len - 2; i++) {
            if (a[i] == 'y' && a[i + 1] == 'o' && a[i + 2] == 'u') {
                a[i] = 'w';
                a[i + 1] = 'e';

                for (int j = i + 2; j < len; j++) {
                    a[j] = a[j + 1];
                }
                len--;
            }
        }
        printf("%s\n", a);
    }
}
