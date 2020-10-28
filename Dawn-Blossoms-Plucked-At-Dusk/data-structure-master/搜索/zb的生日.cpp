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
�Լ�д�Ĵ��볬��ʱ ԭ�������ظ��Ľ�����೬ʱ
ע�͵Ĵ���Ϊac����
��ʵ˼·�ܼ򵥣���������ֵ ͨ�õ�˼·��Ҫ���������� �����������������ϵ�������� 
�˷������Լ���д˼·һ�� ���Լ���д���ظ�����������׳�ʱ
��1 2 3 �ҵķ��������� 1 3 2���� �˷�ʱ�� 
*/
