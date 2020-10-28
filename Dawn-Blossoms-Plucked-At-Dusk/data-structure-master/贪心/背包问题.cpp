#include<stdio.h>

struct bag {
    int per;
    int sum;
};

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int s, m, count = 0;
        struct bag a[10];
        scanf("%d %d", &s, &m);
        for (int i = 0; i < s; i++) {
            scanf("%d %d", &a[i].per, &a[i].sum);
        }
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j < s; j++) {
                if (a[i].per < a[j].per) {
                    int temp, temp1;
                    temp = a[i].per;
                    temp1 = a[i].sum;
                    a[i].per = a[j].per;
                    a[i].sum = a[j].sum;
                    a[j].per = temp;
                    a[j].sum = temp1;
                }
            }
        }
        for (int i = 0; i < s; i++) {
            if (m > a[i].sum) {
                count = count + a[i].sum * a[i].per;
            } else {
                count = count + m * a[i].per;
            }
            m = m - a[i].sum;
            if (m <= 0) break;
        }
        printf("%d\n", count);
    }
}
/*没啥好说的 在重量一定的情况下 要使背包价值最大化 毫无疑问 要将单位价值大的优先装进去 贪心 每一次都装进去当前最大的*/

