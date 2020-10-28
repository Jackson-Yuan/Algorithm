#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int pos[100000];
int n, c;

bool judge(int k) {
    int temp = pos[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] - temp >= k) {
            count++;
            if (count == c) {
                return true;
            }
            temp = pos[i];
        }
    }
    return false;
}

int binarysearch() {
    int left = 0;
    int right = pos[n - 1] - pos[0];
    int mid = (right + left) / 2;
    int result = 0;
    while (left <= right) {
        if (judge(mid)) {
            result = mid;
            left = mid + 1;
        } else if (!judge(mid)) {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return result;
}

int main() {
    while (scanf("%d %d", &n, &c) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &pos[i]);
        }
        sort(pos, pos + n);
        printf("%d\n", binarysearch());
    }
}
/*
此题翻译翻译 其实就是相当于在0开始的正半轴上找若干点 使得若干点的任意两点之间的距离都大于某值，求出这个某值的最大值 
首先写出判断函数，判断当前若干点的任意两点距离是否都大于函数的参数值，同时注意，若干点的第一个点是肯定要分配的，因为是算距离且是尽可能大，所以第一个点肯定要选，然后利用二分查找，left为0 right为若干点的终点位置减去起点值
利用二分来寻找合适的值 
*/
