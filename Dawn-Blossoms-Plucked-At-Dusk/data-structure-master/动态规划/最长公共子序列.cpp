#include<stdio.h>
#include<string.h>

int c[1000][1000];
char str1[1000];
char str2[1000];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", str1);
        scanf("%s", str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        c[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            c[i][0] = 0;
        }

        for (int i = 1; i <= len2; i++) {
            c[0][i] = 0;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - 1];
                }
            }
        }

        printf("%d\n", c[len1][len2]);
    }
}
/*
此题经典动态规划 根据两个子串 得出如下结论
a0a1a2a3a4.......an-1
b0b1b2b3b4.......bm-1
设z0z1z2z3z4.......zk-1为其最长公共子序列
若an-1 = bm-1
则zk-1 = an-1 = bm-1
得出z0z1......zk-2为a0a1....an-2, b0b1b2b3b......bn-2的子序列 

如果an-1 ！= bm-1
那么z0z1.....zk-1 为a0.....an-2, b0........bn-1的子序列 或者 a0........an-1, b0.......bn-2的子序列
取两者中长的

经典的一匹啊 划分子问题 通过子问题递推求出结果
动态的求出每一步的最优解
与贪心的区别
贪心的最优解一定包含上一步的最优解
动态规划的最优解不一定包含上一步的最优解 可能是之前某个局部最优解 
*/
