#include<stdio.h>

int f(char x) {
    int t;
    if (x > 90) {
        t = -f(x - 32);
        return t;
    } else {
        t = x - 64;
        return t;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        int number;
        char letter;
        scanf("%c %d", &letter, &number);
        getchar();
        printf("%d\n", number + f(letter));
    }

}
