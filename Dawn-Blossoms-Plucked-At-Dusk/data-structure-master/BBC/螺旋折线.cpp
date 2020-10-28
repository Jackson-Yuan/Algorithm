#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int dis(int x, int y) {
    if (y == 0 && x == 0) return 0;
    if (y > 0) {
        if (x == 0) return dis(0, y - 1) + 8 * y - 5;
        if (abs(x) <= y) return dis(0, y) + x;
        if (abs(x) > y) {
            if (x > 0) return dis(0, x) + 2 * x - y;
            if (x < 0) return dis(0, -x) + 2 * x + y;
        }
    } else if (y < 0) {
        if (x == 0) return dis(0, -y) - 4 * y;
        if (x >= 0 && x <= abs(y)) return dis(0, y) - x;
        if (x > 0 && x > abs(y)) return dis(0, -x) - 2 * x - y;
        if (x < 0 && abs(x) <= abs(y) + 1) return dis(0, y) - x;
        if (x < 0 && abs(x) > abs(y) + 1) return dis(0, x + 1) - 2 * x + y;
    }
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y)) {
        printf("%d\n", dis(x, y));
    }
}
/*
����Ϊ�ҹ��� �ؼ��������ҳ�dis(0,y)�Ĺ��� ������x֮��Ĺ�ϵ �Ӷ��ó��� 
*/
