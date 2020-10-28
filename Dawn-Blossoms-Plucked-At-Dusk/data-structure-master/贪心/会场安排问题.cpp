#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
struct activity {
    int start;
    int end;
};
struct activity ac[10000];

bool compare(struct activity a, struct activity b) {
    return a.end < b.end;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &ac[i].start, &ac[i].end);
        }
        sort(ac, ac + n, compare);
        int count = 1;
        int tempEnd = ac[0].end;
        for (int i = 1; i < n; i++) {
            if (ac[i].start > tempEnd) {
                count++;
                tempEnd = ac[i].end;
            }
        }
        printf("%d\n", count);
    }
}
/*
此题就是一道经典的贪心  按照每个活动的结束时间排 为什么不按开始时间排 原因很简单 
如果一个开始时间很小 但结束时间很大 那之后的一些结束时间小但开始时间大的 都没的玩 
所以要按照结束时间从小到大排序 毕竟要尽可能多的安排活动 所以要按结束时间顺序排 
*/
