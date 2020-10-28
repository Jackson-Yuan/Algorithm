#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int n, k;
int visited[20];
int result[20];
int a[20];
int flag;

int count(int index) {
    int sum = 0;
    for (int i = 0; i < index; i++) {
        sum += result[i];
    }
    return sum;
}

void dfs(int start, int index) {
    visited[start] = 1;
    result[index] = a[start];
    index++;
    /*if(count(index) > k) return;*/
    if (count(index) == k) {
        if (flag == 0) printf("Yes\n");
        for (int i = 0; i < index; i++) {
            printf("%d ", result[i]);
        }
        flag = 1;
        printf("\n");
    }
    /*visited[start] = 1;
    result[index] = a[start];
    index++;*/
    for (int i = start; i < n; i++) {
        if (visited[i] == 0) {
            dfs(i, index);
        }
    }
    visited[start] = 0;
}

int main() {
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        flag = 0;
        for (int i = 0; i < n; i++) {
            memset(visited, 0, sizeof(visited));
            if (i > 0) {
                for (int j = 0; j < i; j++) {
                    visited[j] = 1;
                }
            }
            dfs(i, 0);
            if (flag == 1) break;
        }
        if (flag == 0) printf("No\n");
    }


}
/*
此题数据有问题 就不做提交oj了
有几个注意点
dfs中当前点到到他能到的点要根据题目意思区分清楚
如这题 若采用常规的从1到n仅仅搜索未访问 标记与题目意思 输入顺序相违背 
还有各种代码的逻辑顺序 要理清
比如注释代码处 第一处 若结果k为0 输入数据为 1 -1则会判断为no
第二处 因为是先判断 在标记 再赋值
则如
n k 为4 13 输入1 2 4 7 
正确答案应该为2 4 7
单如果按第二处注释代码处所写 则有个bug 当把7压入结果数组时  因为7的索引为最后一位 没有办法继续dfs那么久无法判断2 4 7这个组合 
*/
