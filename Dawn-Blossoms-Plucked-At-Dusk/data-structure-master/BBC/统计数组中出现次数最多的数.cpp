#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
int a[100];

int main() {
    int n;
    int count, countMax, target;
    cin >> n;

    if (n <= 0) return 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    count = 1;
    countMax = 1;
    target = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > countMax) {
            countMax = count;
            target = a[i];
        }
    }

    cout << target << endl;
}
/**
此题这种算法前提条件为数组为从小到大有序排列，然后利用相邻两个数的比较，相同就次数加一 ，不相同说明这种数的统计次数，重新开始统计，置统计变量为1，同时统计次数还要与最大统计次数进行比较，保存其结果 
因为已经进行了排序，相同的数肯定被连续的安排在一起，这也是其中的关键
排序还是有点用处的 
*/
