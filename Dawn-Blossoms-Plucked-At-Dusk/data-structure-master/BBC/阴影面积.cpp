#include<stdio.h>

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

int main() {
    int x1, y1, x2, y2;    //矩形1
    int x3, y3, x4, y4;    //矩形2
    int m1, n1;        //交集左上角坐标.
    int m2, n2;        //交集右下角坐标.
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
    m1 = max(min(x1, x2), min(x3, x4));
    n1 = max(min(y1, y2), min(y3, y4));
    m2 = min(max(x1, x2), max(x3, x4));
    n2 = min(max(y1, y2), max(y3, y4));
    int middle;
    if (m2 > m1 && n2 > n1)


            else

    printf("0.00\n");

    return 0;

