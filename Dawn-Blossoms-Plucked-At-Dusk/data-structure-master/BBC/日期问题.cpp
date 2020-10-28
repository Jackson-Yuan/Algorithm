#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

bool panduan(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int a, b, c, year, month, day;
struct date {
    int year;
    int month;
    int day;
};
struct date d[3];

bool cmp(struct date a, struct date b) {
    if (a.year == b.year) {
        if (a.month == b.month) return a.day < b.day;
        else return a.month < b.month;
    } else return a.year < b.year;
}

int select(int a, int b, int c) {
    int flag = 1;
    if (a >= 0 && a <= 59) {
        year = 2000 + a;
    } else if (a >= 60 && a <= 99) {
        year = 1900 + a;
    } else flag = 0;
    if (b >= 1 && b <= 12) {
        month = b;
    } else flag = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (c >= 1 && c <= 31) day = c;
        else flag = 0;
    } else if (month != 2) {
        if (c >= 1 && c <= 30) day = c;
        else flag = 0;
    } else {
        if (panduan(year) && c >= 1 && c <= 29) {
            day = c;
        } else if (!panduan(year) && c >= 1 && c <= 28) {
            day = c;
        } else flag = 0;
    }
    return flag;
}

int main() {
    int flag;
    int index = 0;
    scanf("%d/%d/%d", &a, &b, &c);
    /**年月日*/
    flag = select(a, b, c);
    if (flag) {
        d[index].year = year;
        d[index].month = month;
        d[index].day = day;
        index++;
    }
    /**月日年*/
    flag = select(c, a, b);
    if (flag) {
        d[index].year = year;
        d[index].month = month;
        d[index].day = day;
        index++;
    }
    /**日月年*/
    flag = select(c, b, a);
    if (flag) {
        d[index].year = year;
        d[index].month = month;
        d[index].day = day;
        index++;
    }
    sort(d, d + index, cmp);
    printf("%d-%02d-%02d\n", d[0].year, d[0].month, d[0].day);
    for (int i = 1; i < index; i++) {
        if (!(d[i].year == d[i - 1].year && d[i].month == d[i - 1].month && d[i].day == d[i - 1].day)) {
            printf("%d-%02d-%02d\n", d[i].year, d[i].month, d[i].day);
        }
    }
    return 0;
}
