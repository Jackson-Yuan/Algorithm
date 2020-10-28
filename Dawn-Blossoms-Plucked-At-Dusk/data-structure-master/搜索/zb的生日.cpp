#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int visited[21];
int result;
int watermelon[21];
int total;
int n;

void dfs(int index, int sum) {
    if (visited[index] == 1) return;
    sum = sum + watermelon[index];
    int other = total - sum;
    if (result > (abs(other - sum))) {
        result = abs(other - sum);
    }
    visited[index] = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i, sum);
        }
    }
    visited[index] = 0;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        total = 0;
        result = 100000;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &watermelon[i]);
            total = total + watermelon[i];
        }
        dfs(1, 0);
        printf("%d\n", result);
    }
}
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int a[110],s;
void dfs(int s1,int s2,int i)
{
if(i==n)
{
if(abs(s1-s2)<s)
s=abs(s1-s2);
return ;
}
dfs(s1+a[i+1],s2,i+1);
dfs(s1,s2+a[i+1],i+1);
}
int main()
{
while(~scanf("%d",&n))
{
memset(a,0,sizeof(a));
int i;
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}
s=0xffffff;
dfs(0,0,0);
printf("%d\n",s);
}
}*/


/*
自己写的代码超了时 原因大概是重复的结果过多超时
注释的代码为ac代码
其实思路很简单，凡是求最值 通用的思路都要穷举所有情况 此题就是穷举两堆西瓜的所有情况 
此方法与自己所写思路一样 但自己所写有重复的情况，容易超时
如1 2 3 我的方法还会有 1 3 2出现 浪费时间 
*/
