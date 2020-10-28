#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
struct node {
    int length;
    int weight;
};

bool compare(struct node a, struct node b) {
    if (a.weight == b.weight) return a.length < b.length;
    else return a.weight < b.weight;
}

int visited[5000];
struct node a[5000];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        int count = 0;
        scanf("%d", &n);
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].length, &a[i].weight);
        }
        sort(a, a + n, compare);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            count++;
            int tempLength = a[i].length;
            int tempWeight = a[i].weight;
            for (int j = i + 1; j < n; j++) {
                if (visited[j] == 1) continue;
                if (a[j].weight >= tempWeight && a[j].length >= tempLength) {
                    visited[j] = 1;
                    tempLength = a[j].length;
                    tempWeight = a[j].weight;
                }
            }
        }
        printf("%d\n", count);
    }
}
/*
此题 贪心没啥好说的 
具体表现为 因题目表明第i+1个木棒如果长度，重量都大于等于第i个木棒 那么第i+1个木棒则不耗费时间  
首先需要排序 组织一波数据 为什么要排序 理由很简单 这个题目大致思路是选取一个木棍 遍历剩余的木棍 看看有多少个木棍能跟选定的木棍组成一组 
接着再从剩下没组的再选定一个木棍 重回福刚才的步骤 知道都分组完 那么有多少组数 就耗费多少时间 
如果不排序 那么每个分组的木棍的个数就不可能尽可能的多 排序的原则 可以按weight排 也可以按length排 这两个值没有关系 完全随机 所以两者地位等价 按照哪个排结果都一样 
*/
