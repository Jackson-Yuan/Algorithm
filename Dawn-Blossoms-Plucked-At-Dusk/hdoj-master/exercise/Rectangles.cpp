/**
 * Given two rectangles and the coordinates of two points on the diagonals of each rectangle,
 * you have to calculate the area of the intersected part of two rectangles. its sides are parallel to OX and OY .
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double minX1 = max(min(x1, x2), min(x3, x4));/**重叠部分靠左的x坐标*/
        double maxX2 = min(max(x1, x2), max(x3, x4));/**重叠部分靠右的x坐标*/
        double minY1 = max(min(y1, y2), min(y3, y4));/**重叠部分靠下的y坐标*/
        double maxY2 = min(max(y1, y2), max(y3, y4));/**重叠部分靠上的y坐标*/

        if (minX1 >= maxX2 || minY1 >= maxY2) cout << "0.00" << endl;/**若靠左的x大于靠右的x 或 靠下的y大于靠上的y 则不可能重叠*/
        else {
            double res = (maxX2 - minX1) * (maxY2 - minY1);
            printf("%.2lf\n", res);
        }
    }

    return 0;
}
/**
 * 矩形重叠问题的标准解法
 * */