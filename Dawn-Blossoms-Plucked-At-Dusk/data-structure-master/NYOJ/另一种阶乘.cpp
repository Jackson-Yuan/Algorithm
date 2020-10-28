#include<stdio.h>

int special(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0)
        return special(n - 1);
    else return n * special(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int t, sum = 0;
        scanf("%d", &t);
        for (int i = 1; i <= t; i++) {
            sum = sum + special(i);
        }
        printf("%d\n", sum);
    }

}
