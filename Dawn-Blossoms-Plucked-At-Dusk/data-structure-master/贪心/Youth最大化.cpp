#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
double v[10005];
double w[10005];
double s[10005];
int n, k;

bool judge(double value) {
    for (int i = 0; i < n; i++) {
        s[i] = v[i] - value * w[i];
    }
    sort(s, s + n);
    double sum = 0;
    int index = n - 1;
    int count = k;
    while (count--) {
        sum += s[index];
        index--;
    }
    if (sum >= 0) return true;
    else return false;
}

void search(double left, double right) {
    while (right > left + 0.0000001) {
        double mid = (left + right) / 2;
        if (judge(mid)) left = mid;
        else right = mid;
    }
    printf("%.2lf\n", left);
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        double max = -1;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &w[i], &v[i]);
            double temp = v[i] / w[i];
            if (temp > max) max = temp;
        }
        search(0, max);
    }
}
/*
此题不能按照想当然 按照性价比从大到小排一下，取前k个 
反例 10 5  20 11   20 60
真正的思路 其实是圈定这个性价比的范围 利用二分查找 判断
判断流程 也有讲究 若v[i]/w[i]>=x 则 v[i] - x * w[i]>=0
将判断的性价比带入judge函数 将每个物品与此性价比比较 排序
取最大的前k个 看是否和大于0 若大于等于0 代表 前k个组合起来大于此性价比 可以继续放大 则将left赋值为mid
小于0 则right赋值为mid 其中二分循环判断的条件不再是left<right 而是 right - left > 0.00000001 因为是浮点数
 单纯的left 《 right 不可能跳出循环的 就采用差值大于0.0000001消除精度(记着吧) 
*/ 
