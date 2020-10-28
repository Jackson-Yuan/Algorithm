#include<stdio.h>

char a[10000];
int count[10000];

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    while (n--) {
        scanf("%s", a);
        int n = 0;
        while (a[n] != '\0') {
            n++;
        }

        for (int i = 0; i < n; i++) {
            count[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && count[i] < count[j] + 1) {
                    count[i] = count[j] + 1;
                }
            }
        }
        int max = count[0];
        for (int i = 0; i < n; i++) {
            if (max < count[i]) max = count[i];
        }
        printf("%d\n", max + 1);
    }
}
