/**
 * 看原网页把 hdoj2073
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
struct point {
    int x;
    int y;
};

int main() {
    int n;
    cin >> n;
    struct point start, end;
    while (cin >> start.x >> start.y >> end.x >> end.y) {
        if (start.x + start.y > end.x + end.y) {
            struct point tmp = start;
            start = end;
            end = tmp;
        }

        double res = 0;
        if (start.x == 0 && start.y == 0) {
            start.y = 1;
            res += 1;
        }

        if (end.x == 0 && end.y == 0) {
            end.y = 1;
            res -= 1;
        }

        /**移动起点至便于计算的点*/
        int tmp = start.x + start.y;
        struct point tmpPoint;
        tmpPoint.x = 0;
        tmpPoint.y = tmp;
        double len = pow(start.x - tmpPoint.x, 2) + pow(start.y - tmpPoint.y, 2);
        len = sqrt(len);
        res -= len;
        start.x = 0;
        start.y = tmp;

        /**移动终点至便于计算的点*/
        tmp = end.x + end.y;
        tmpPoint.x = 0;
        tmpPoint.y = tmp;
        len = pow(end.x - tmpPoint.x, 2) + pow(end.y - tmpPoint.y, 2);
        len = sqrt(len);
        res += len;
        end.x = 0;
        end.y = tmp;

        int count = end.y - start.y;
        int startValue = start.y;
        while (count--) {
            double val = sqrt(2) * startValue;
            res += val;
            val = pow(startValue + 1, 2) + pow(startValue, 2);
            val = sqrt(val);
            res += val;
            ++startValue;
        }

        printf("%.3lf\n", res);
    }
    return 0;
}
/**
 * 此题其实就是注意观察，点的x值加y值为跨(0, x+y)到(x+y, 0)两点的直线上，可以先移动他们统一至(0, x+y)点，总长相应变化，便于计算
 * 同时(0,0)这个点需特殊处理，调至(0,1)点，总长也要变化
 * */