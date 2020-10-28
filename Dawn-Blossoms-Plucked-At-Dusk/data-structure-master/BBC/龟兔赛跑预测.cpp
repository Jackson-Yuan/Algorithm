#include<stdio.h>

int main() {
    int v1, v2;
    int t, s, l;
    scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
    int tortiseTime = l / v2;
    int rabbitTime = 0;
    int tortiseDistance = 0;
    int rabbitDistance = 0;
    for (int i = 1; i <= tortiseTime; i++) {
        /*此为当前秒数 在加距离之前 先判断一波距离差 小于设定值 两者都加 否则只加乌龟*/
        if (rabbitDistance - tortiseDistance < t) {
            rabbitDistance += v1;
            tortiseDistance += v2;
        } else {
            /*只加乌龟时注意 要加到兔子休息完开始再一次判断距离时代码中start(休息时不判断距离差) 同时由于循环 会自增 所以要减去1*/
            int start = i + s;
            int temp = i;
            i = start - 1;
            /*乌龟所要加的距离 是经过处理后的i 与处理前的的差+1*/
            tortiseDistance += (i - temp + 1) * v2;
        }
        /*兔子所消耗的时间 就是当前i值*/
        rabbitTime = i;
        /*等数据加完后 若兔子距离已经大于等于最后长度 则直接结束循环 因为循环变量的最大值为乌龟时间 如果提前结束 说明兔子已经提前到达终点*/
        if (rabbitDistance >= l) break;
    }
    if (tortiseDistance > rabbitDistance) {
        printf("T\n");
        printf("%d\n", tortiseTime);
    } else if (tortiseDistance < rabbitDistance) {
        printf("R\n");
        printf("%d\n", rabbitTime);
    } else {
        printf("D\n");
        printf("%d\n", tortiseTime);
    }
}
/*
做题思路 还是脑袋清爽 运用实际例子推导抽象规则 慢慢来 不着急 稳住 
*/
