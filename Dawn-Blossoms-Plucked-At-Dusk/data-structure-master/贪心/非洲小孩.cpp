#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
struct node {
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};
struct node a[100];

bool temp(struct node a, struct node b) {
    if (a.endHour == b.endHour) return a.endMinute <= b.endMinute;
    else return a.endHour < b.endHour;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d:%d-%d:%d", &a[i].startHour, &a[i].startMinute, &a[i].endHour, &a[i].endMinute);
            if ((a[i].startHour > a[i].endHour) ||
                (a[i].startHour == a[i].endHour && a[i].startMinute > a[i].endMinute)) {
                int value = a[i].startHour;
                a[i].startHour = a[i].endHour;
                a[i].endHour = value;
                value = a[i].startMinute;
                a[i].startMinute = a[i].endMinute;
                a[i].endMinute = value;
            }
        }
        sort(a, a + n, temp);
        count++;
        struct node temp = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i].startHour > temp.endHour) {
                temp = a[i];
                count++;
            } else if (temp.endHour == a[i].startHour && a[i].startMinute > temp.endMinute) {
                temp = a[i];
                count++;
            }
        }
        printf("%d\n", count);
    }
}
/*此题本质上是区间覆盖问题  区间覆盖前组织数据一定要保证左端点小于右端点
然后按照右端点大小排序  不能按左端点排序 这样会让个数减小 例如
0 10,11 30,12 20,23 25
按右端点排序 答案为2 但实际上是错误的  第三个区间和第四个区间没有公共点 随意 后面三个区间不可能有三者的公共点
如果按右端点排序 0 10,12 20,23 25,11 30 答案3 正确 
*/
