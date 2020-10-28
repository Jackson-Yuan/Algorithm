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
    if (row < 1 || row > r || col < 1 || col > r || height < map[row][col]) return 0;//���˱߽� �� �߶�û��ǰһ�����

    if (value[row][col] >= 0) return value[row][col];//�Ѿ����ع��� ֱ����ô�����ʷ���

    /*���� ��ʼ����״̬ת�Ʒ��� �������ĸ����� ѡ����� �ĸ��ֲ����Ÿ������ȫ������*/
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
������Ҫ�Ƕ�̬�滮�����ѵ��ۺ�Ӧ�� ������������  �����ҵ����Թ��е��·�� ��Ϊ��㲻ͬ ���Բ�ͬ����в�ͬ�ľ��� Ҫ��ÿ���㶼����һ�� ��ʱ�������˼· ÿ����ֱ�ӱ���
�ȶԳ����ֵ ��Ȼ��Ҳ��ʱ���� ����������dfs ��dfs������ ��¼ÿ��������������������(�ֲ����Ž�) ÿ�������������ʵ���Ƕ����������ĸ�����ľֲ����Ž�������(����) 
��������dfs���Ը����Զ�̬�滮 ���� ��Ҫ�����ȵ� �����ڵݹ������ ĳЩ���������Ľ�����Ը��� ��ʡʱ��
���⵱ʱ�ĳ��������˵�����ĸ����������������Ž� ���ĸ��������������ô�����ѵ� ����dfs�ɽ�� 
*/

/*
���ϱ�������

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
