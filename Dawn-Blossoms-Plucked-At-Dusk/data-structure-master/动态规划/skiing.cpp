#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
int map[103][103];
int value[103][103];
int r, c;

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int dfs(int row, int col, int height) {
    if (row < 1 || row > r || col < 1 || col > r || height < map[row][col]) return 0;//出了边界 或 高度没有前一个点高

    if (value[row][col] >= 0) return value[row][col];//已经搜素过了 直接特么给劳资返回

    /*否则 开始动归状态转移方程 来自于四个方向 选最大者 四个局部最优搞出最后的全局最优*/
    value[row][col] =
            max(dfs(row - 1, col, map[row][col]), dfs(row + 1, col, map[row][col]), dfs(row, col + 1, map[row][col]),
                dfs(row, col - 1, map[row][col])) + 1;

    return value[row][col];
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int max = 0;
        memset(value, -1, sizeof(value));
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= r; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= r; j++) {
                int num = dfs(i, j, 99999999);
                if (max < num) max = num;
            }
        }

        printf("%d\n", max);
    }
}
/*
此题主要是动态规划加深搜的综合应用 问题很容易理解  就是找到在迷宫中的最长路径 因为起点不同 所以不同起点有不同的距离 要把每个点都遍历一遍 当时最基本的思路 每个点直接爆搜
比对出最大值 当然这也耗时严重 所以先利用dfs 在dfs过程中 记录每个点的所能延伸的最大距离(局部最优解) 每个点的最大距离其实都是都是依靠它四个方向的局部最优解来迭代(动归) 
此题利用dfs特性辅助以动态规划 好题 需要熟练度的 并且在递归过程中 某些点搜索出的结果可以复用 节省时间
此题当时的初步设想就说利用四个方向来迭代出最优解 但四个方向的最大距离怎么算是难点 利用dfs可解决 
*/

/*
附上暴力代码

#include<stdio.h>
int a[100][100];
int count,max;
int m,n;
void dfs(int x,int y)
{
	if((y+1)<n&&a[x][y]>a[x][y+1])
	{
		count++;
		dfs(x,y+1);
		count--;
	}
	if((y-1)>=0&&a[x][y]>a[x][y-1])
	{
		count++;
		dfs(x,y-1);
		count--;
	}
	if((x+1)<m&&a[x][y]>a[x+1][y])
	{
		count++;
		dfs(x+1,y);
		count--;
	}
	if((x-1)>=0&&a[x][y]>a[x-1][y])
	{
		count++;
		dfs(x-1,y);
		count--;
	}
	if(count>max)
	{
		max=count;
		
	}
} 
int main()
{
	int z;
	scanf("%d",&z);
	while(z--)
	{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	count=max=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			count=1;
			dfs(i,j);
		}
	}
	printf("%d\n",max);
    }
} 
*/ 
