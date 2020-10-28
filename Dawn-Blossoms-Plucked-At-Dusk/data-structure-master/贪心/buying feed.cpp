#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
struct store {
    int location;
    int size;
    int value;
};
struct store a[100];

bool compare(struct store a, struct store b) {
    return a.value < b.value;
}

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        while (t--) {
            int k, e, n;
            scanf("%d%d%d", &k, &e, &n);
            for (int i = 0; i < n; i++) {
                int tempValue;
                scanf("%d%d%d", &a[i].location, &a[i].size, &tempValue);
                a[i].value = (e - a[i].location) + tempValue;
            }
            sort(a, a + n, compare);
            int min = 0;
            for (int i = 0; i < n; i++) {
                if (k > a[i].size) {
                    min += a[i].size * a[i].value;
                    k = k - a[i].size;
                } else {
                    min += k * a[i].value;
                    break;
                }
            }
            printf("%d\n", min);
        }
    }
}
/*
此题就是绕了个弯弯  本质上跟贪心背包问题一样 只不过再算每个商店feed的单价时时除了他本身的单价 还需要加上运费 这样的组合单价
这样按照组合单价从小到大排序 可以选取要买feed的几个商家 同时值得一提的是 可能会有疑虑 这样就不是按顺序买的了 可能还会折返路程
其实并不是这样 利用贪心只是选取要买的商家 真正买的时候是按顺序买的 贪心只是提供要买的商家及商家对应所买的feed数量
就是一个转化的问题 
*/
