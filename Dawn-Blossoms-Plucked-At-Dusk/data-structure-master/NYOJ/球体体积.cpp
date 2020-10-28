#include<stdio.h>

#define pi 3.1415926

int main() {
    double n;
    while (scanf("%lf", &n)) {
        double sum = 4 * pi * n * n * n / 3;
        sum += 0.5;
        printf("%d\n", (int) sum);
    }

}
/*四舍五入处理方法*/
