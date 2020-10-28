/**
 * 输入n个点坐标，算出其代表多边形的面积
 * p2036
 * */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
struct point {
    double x;
    double y;
};

double getRes(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<point> points;
        for (int i = 0; i < n; ++i) {
            point cur;
            cin >> cur.x >> cur.y;
            points.push_back(cur);
        }

        double res = 0;
        for (int i = 0; i < points.size(); ++i) {
            if (i != points.size() - 1) res += getRes(points[i], points[i + 1]);
            else res += getRes(points[i], points[0]);
        }

        printf("%.1lf\n", res / 2);
    }
    return 0;
}
/**
 * 此题严重注意
 * 其实是利用叉乘法进行计算
 * 但这是二维坐标，二维坐标如何计算外积
 * 看成三维，只不过第三维为0(x1,y1,0) (x2,y2.0)
 * 那么最后的记过为(x1y2 - y1x2)K,它的模长即为以两向量为边的平行四边形面积
 * 即|x1y2 - y1x2|
 * 求多边形面积，可以随便以一个点为基点，将多边形两两相邻的点与基点当两向量求叉积
 * 求凸多边形时，可以直接按模长加，但求凹多边形时，x1y2 - y1x2不取绝对值，
 * 该正该负，会将多出的抵消，所以
 * 求多边形面积直接x1y2 - y1x2相加即可
 ** */