/**
 * 给定一个日期，输出这个日期是该年的第几天
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
    int year, mouth, day;
    int mouthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (scanf("%d/%d/%d", &year, &mouth, &day) != EOF) {
        /**多组数据，注意2月的数据需还原*/
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) mouthDays[1] = 29;
        else mouthDays[1] = 28;
        int res = 0;
        for (int i = 0; i < mouth - 1; ++i) {
            res += mouthDays[i];
        }

        res += day;

        printf("%d\n", res);
    }

    return 0;
}