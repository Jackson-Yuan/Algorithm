#include<stdio.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        float a, b, c, temp, s;
        int sum = 0;
        scanf("%f %f %f", &a, &b, &c);
        if ((b >= 2 * c) || (c * c - b * b / 4 < 0.25)) {
            printf("impossible\n");
            continue;
        }
        temp = c * c - b * b / 4;
        temp = 2 * sqrt(temp);
        s = temp;
        sum++;
        while (s < a) {
            s = s + temp;
            sum++;
        }
        printf("%d\n", sum);
    }
}
