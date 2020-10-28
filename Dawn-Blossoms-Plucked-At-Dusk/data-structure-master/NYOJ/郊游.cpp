#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        float x, m, y, z;
        float t, sum;
        scanf("%f %f %f %f", &m, &x, &y, &z);
        t = x * m / (y - x);
        sum = t * z;
        printf("%.2f\n", sum);

    }
}
