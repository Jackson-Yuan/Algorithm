#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;
int map[100][100];
int result[100];
int r, c;
int a[100];

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int maxValue = -999999999;
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        /*主要思路 二维转一维 然后相当于最大连续子串和 怎么转 需要操作的*/
        for (int i = 0; i < r; i++) {
            /*从i行加到j行 每次i循环一次 意味着是个新的起点 要重置result数组*/
            memset(result, 0, sizeof(result));
            for (int j = i; j < r; j++) {
                /*每当j循环一次 意味着要增加一行数据合并  sum代表result[i]中一维数组 每个连续到i的最大值 见如下代码 每次求出一个result[i] 都要计算连续到result[i]时的最大值 再将sum与真正的最大值做比较
                大于就替换max值 小于就拉倒
                 */
                int sum = 0;
                for (int k = 0; k < c; k++) {
                    result[k] += map[j][k];
                    if (sum > 0) sum += result[k];
                    else sum = result[k];
                    maxValue = max(sum, maxValue);
                }

            }
        }

        printf("%d\n", maxValue);
    }
}
/*此题其实就是突出一个转化思想 同时在dp时的操作也是掌握在对最大连续子串和算法 
掌握的基础上成立的
有些题目还是要好好理解啊 操了 
*/
