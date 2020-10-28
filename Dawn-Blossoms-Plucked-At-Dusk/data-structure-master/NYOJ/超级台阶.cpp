#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int s[41];
    while (n--) {
        int m;
        scanf("%d", &m);
        s[1] = 0;
        s[2] = 1;
        s[3] = 2;
        for (int i = 4; i <= m; i++) {
            s[i] = s[i - 1] + s[i - 2];
        }
        printf("%d\n", s[m]);
    }
}
