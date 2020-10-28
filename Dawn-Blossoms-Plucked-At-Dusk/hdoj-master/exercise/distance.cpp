/**
 * 输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
    double x1, y1;
    double x2, y2;
    double res;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        res = pow((x1 - x2), 2) + pow((y1 - y2), 2);

        res = sqrt(res);
        printf("%.2f\n", res);
    }

    return 0;
}