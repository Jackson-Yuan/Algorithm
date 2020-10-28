/*#include<stdio.h>
struct qujian
{
	int start;
	int end;
};
struct qujian a[100];
int main()
{
	int n;
    while(scanf("%d",&n))
    {
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].start,&a[i].end);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].end>a[j].end)
			{
				int temp=a[i].start;
				a[i].start=a[j].start;
				a[j].start=temp;
				temp=a[i].end;
				a[i].end=a[j].end;
				a[j].end=temp;
			}
		}
	}
	int count=1;
	
	int endd=a[0].end;
	
	for(int i=1;i<n;i++)
	{
		if(a[i].start>endd)
		{
			count++;
			endd=a[i].end;
		}
	}
	
	printf("%d\n",count);
}
}*/
#include<iostream>
#include <algorithm>

using namespace std;
struct act {
    int x, y;
};

bool cmp(act a, act b) {
    return a.y < b.y;
}

int main() {
    act a[100];
    int n, i;
    while (cin >> n) {
        int sum = 1, j;
        for (i = 0; i < n; i++)
            cin >> a[i].x >> a[i].y;
        sort(a, a + n, cmp);

        i = 0;
        for (j = i + 1; j < n; j++) {
            if (a[j].x > a[i].y) {
                sum++;
                i = j;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
/*
贪心思路 ，按照右端点的值从小到大排列，再将左端点与右端点进行比较 如果不按次顺序排列 返例 18 35 67 
值得注意，排序时sort方法比自己写的冒泡快，否则超时 
*/ 
