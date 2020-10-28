/**
 * 二分查找的一些操作
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/**数组a中返回第一个大于等于target的元素的位置(也可用于寻找target位置)*/
int halfSearchBiggerOrEqualX(int *a, int len, int target) {
    int left = 0, right = len;/**right此处为n而非n-1 防止target大于数组所有元素，返回数组长度代表不存在或代表如果存在的话应该呆的位置*/
    while (left < right) {/**没有等号为的是利用夹逼夹出来*/
        int mid = left + (right - left) / 2;
        if (a[mid] >= target) right = mid;
        else left = mid + 1;
    }

    return left;
}

/**寻找数组a中等于target的元素的位置*/
int halfSearchEqualX(int *a, int len, int target) {
    int left = 0, right = len - 1;/**此处right为n-1没啥说头*/
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > target) right = mid - 1;
        else if (a[mid] < target) left = mid + 1;
        else return mid;
    }

    return -1;
}

/**寻找数组a中第一大于target元素的位置*/
int halfSearchBiggerX(int *a, int len, int target) {
    int left = 0, right = len;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > target) right = mid;
        else left = mid + 1;
    }

    return left;
}

/**自定义sqrt函数，利用二分法*/
double diySqrt(int val, double left, double right) {
    const double dif = 1e-5;
    double mid = 0;
    while (right - left > dif) {
        mid = (right + left) / 2;
        if (mid * mid > val) {
            right = mid;
        } else left = mid;
    }

    return mid;
}

int main() {
    int a[10] = {1, 2, 3, 4, 6, 6, 7, 8, 9, 10};
    cout << diySqrt(2, 1, 2);
}