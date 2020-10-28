/**
问题描述
　　长100厘米的细长直杆子上有n只蚂蚁。它们的头有的朝左，有的朝右。

　　每只蚂蚁都只能沿着杆子向前爬，速度是1厘米/秒。

　　当两只蚂蚁碰面时，它们会同时掉头往相反的方向爬行。

　　这些蚂蚁中，有1只蚂蚁感冒了。并且在和其它蚂蚁碰面时，会把感冒传染给碰到的蚂蚁。

　　请你计算，当所有蚂蚁都爬离杆子时，有多少只蚂蚁患上了感冒。
输入格式
　　第一行输入一个整数n (1 < n < 50), 表示蚂蚁的总数。

　　接着的一行是n个用空格分开的整数 Xi (-100 < Xi < 100), Xi的绝对值，表示蚂蚁离开杆子左边端点的距离。正值表示头朝右，负值表示头朝左，数据中不会出现0值，也不会出现两只蚂蚁占用同一位置。其中，第一个数据代表的蚂蚁感冒了。
输出格式
　　要求输出1个整数，表示最后感冒蚂蚁的数目。
样例输入
3
5 -2 8
样例输出
1
样例输入
5
-10 8 -20 12 25
样例输出
3
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
struct ant {
    int location;
    int flag;
};

bool cmp(struct ant a, struct ant b) {
    return abs(a.location) < abs(b.location);
}

struct ant a[50];

int main() {
    int n, flag, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].location;
        if (i == 0) a[i].flag = 1;
        else a[i].flag = 0;
    }

    sort(a, a + n, cmp);
    while (1) {
        int flag = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].location > 0 && a[i + 1].location < 0) {
                flag = 0;
                break;
            }
        }
        if (flag) break;


        for (int i = 0; i < n - 1; i++) {
            if (a[i].location > 0 && a[i + 1].location < 0) {
                flag = 0;
                a[i].location = -a[i].location;
                a[i + 1].location = -a[i + 1].location;
                if (a[i].flag == 1 || a[i + 1].flag == 1) {
                    a[i].flag = 1;
                    a[i + 1].flag = 1;
                }
                i++;//可以不加 但加了更符合逻辑
            }
        }

        sort(a, a + n, cmp);

    }

    for (int i = 0; i < n; i++) {
        if (a[i].flag == 1) count++;
    }
    cout << count << endl;
}
/**
根据题意 可以得出 一个蚂蚁向右走 一个蚂蚁向左走 且向右走的蚂蚁所处位置比向左走蚂蚁所处位置小 那么必相撞
所以先按照题意 利用绝对值进行排序 再进行相邻的蚂蚁的位置值进行判断 如果i 与 i + 1 两个蚂蚁可以碰撞 那么位置取反(调头)
同时让i先行自增 确保下一次循环取到i + 2 而不是 i + 1(单次循环 就撞一次 更符合逻辑)
这样循环判断 直到出现不再可能出现碰撞为止(一定要循环 如下情况-> <- -> <-) 不循环不全面
ps：本来想模拟蚂蚁的行走来判断的  但发现根本不可能 因为所有蚂蚁的行走时同时进行的 不可能模拟这种效果，要另谋出路 
*/ 
