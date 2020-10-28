#include<stdio.h>
#include<string.h>

int main() {
    char str[40];
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        char b[40];
        int a, c = 0;
        gets(str);
        a = strlen(str);
        for (int j = a - 1; j >= 0; j--) {
            if (str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z') {
                b[c] = str[j];
                c++;
            }
        }

        for (int j = 0; j < c; j++) {
            printf("%c", b[j]);
        }
        printf("\n");
    }
}
