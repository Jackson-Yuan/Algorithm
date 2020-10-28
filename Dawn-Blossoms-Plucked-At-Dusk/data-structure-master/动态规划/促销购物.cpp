/**
第一行促销物品的种类数（0  < =  s  < =  99）。 
第二行..第s+1  行每一行都用几个整数来表示一种促销方式。 
第一个整数  n  （1  < =  n  < =  5），表示这种优惠方式由  n  种商品组成。 
后面  n  对整数  c  和  k  表示  k  （1  < =  k  < =  5）个编号为  c  （1  < =  c  < =  999）的商品共同构成这种方案。 
最后的整数  p  表示这种优惠的优惠价（1  < =  p  < =  9999）。也就是把当前的方案中的物品全买需要的价格。 
第  s+2  行这行一个整数b  （0  < =  b  < =  5），表示需要购买  b  种不同的商品。 
第  s+3  行..第  s+b+2  行这  b  行中的每一行包括三个整数：c  ，k  ，和  p  。 
C  表示唯一的商品编号（1  < =  c  < =  999）， 
k  表示需要购买的  c  商品的数量（1  < =  k  < =  5）。 
p  表示  c  商品的原价（1  < =  p  < =  999）。 
最多购买  5*5=25  个商品。

一个整数ans，表示需要花的最小费用 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

#define INF 0x3f3f3f3f
using namespace std;
int res[6][6][6][6][6];
struct cuxiao {
    int num[1000];
    int total;
};
struct good {
    int c;
    int k;
    int p;
};
struct cuxiao a[100];
struct good b[100];

int main() {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int kind;
        cin >> kind;
        for (int j = 0; j < kind; j++) {
            int c, k;
            cin >> c >> k;
            a[i].num[c] = k;
        }
        cin >> a[i].total;
    }

    int bb;
    cin >> bb;
    for (int i = 0; i < bb; i++) {
        cin >> b[i].c >> b[i].k >> b[i].p;
        a[s].total = b[i].p;
        a[s].num[b[i].c] = 1;
        s++;
    }

    memset(res, INF, sizeof(res));
    res[0][0][0][0][0] = 0;
    int b1, b2, b3, b4, b5, m1, m2, m3, m4, m5;
    for (int i = 0; i < s; i++) {
        b1 = a[i].num[b[0].c];
        b2 = a[i].num[b[1].c];
        b3 = a[i].num[b[2].c];
        b4 = a[i].num[b[3].c];
        b5 = a[i].num[b[4].c];
        for (m1 = b1; m1 <= b[0].k; m1++) {
            for (m2 = b2; m2 <= b[1].k; m2++) {
                for (m3 = b3; m3 <= b[2].k; m3++) {
                    for (m4 = b4; m4 <= b[3].k; m4++) {
                        for (m5 = b5; m5 <= b[4].k; m5++) {
                            res[m1][m2][m3][m4][m5] = min(res[m1][m2][m3][m4][m5],
                                                          res[m1 - b1][m2 - b2][m3 - b3][m4 - b4][m5 - b5] +
                                                          a[i].total);
                        }
                    }
                }
            }
        }
    }
    cout << res[b[0].k][b[1].k][b[2].k][b[3].k][b[4].k] << endl;
}
/**
此题 官方解法动态规划(日翔 怎么这么多动态规划)
先申明两个结构体 保存促销方法 和 所需要买的东西
值得注意的是 在保存所需要买的东西时 也要把所需买物品的单价当成一个促销方案 方便动态规划的状态转移方程递推
动态规划的主要思路为 建立一个五维数组(因题目要求五种商品,如果买了四种 第五种默认就是0 无影响) 此数组下标为各种物品买的个数，随意对应数组的含义为各种商品的各个商品个数情况下最小的价格
规划的顺序为 用一个for循环遍历所有促销方案 用五个变量保存每个方案对所需物品种类的个数
状态转移方程也很好理解 就是将本次五个种类的个数 与 减去本次循环方案对应的物品个数的状态的加上本次促销方案的优惠价格进行比较，取小的一方

目前来说就是看看 看起来好理解 自己想还是有难度 
*/
