/**
 * 根据输入的半径值，计算球的体积。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stdio.h>

#define PI 3.1415927
using namespace std;

int main() {
    double len;

    while (cin >> len) {
        double res = (4 * PI * pow(len, 3)) / 3;
        printf("%.3f\n", res);
    }

    return 0;
}