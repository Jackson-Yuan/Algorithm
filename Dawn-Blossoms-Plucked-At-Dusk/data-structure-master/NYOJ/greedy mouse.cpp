#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>

using namespace std;
struct node {
    int w;
    int f;
    double cost;
};

bool cmp(struct node a, struct node b) {
    return a.cost > b.cost;
}

struct node weight[1000];

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n)) {
        if (m == -1 && n == -1) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &weight[i].w, &weight[i].f);
            weight[i].cost = (double) weight[i].w / (double) weight[i].f;
        }
        sort(weight, weight + n, cmp);
        double sum = 0;
        for (int i = 0; i < n; i++) {
            if (m - weight[i].f >= 0) {
                sum = sum + weight[i].w;
                m = m - weight[i].f;
            } else if (m - weight[i].f < 0 && m > 0) {
                double temp = ((double) m / (double) weight[i].f) * weight[i].w;
                sum = sum + temp;
                break;
            }
        }
        printf("%.3f\n", sum);
    }
}
/*
没啥好说的 就是算出每个粮仓需要猫粮与老鼠所爱食的性价比 ，按从大到小排序即可 

*/
