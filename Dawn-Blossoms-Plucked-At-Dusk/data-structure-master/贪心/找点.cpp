#include<iostream>
#include<string.h>
#include<cstdlib>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;
/*struct Node
{
	int x,y;
}a[108];
bool cmp(Node a,Node b)
{
	return a.x<b.x;
}
int main()
{
	int n,m;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i].x>>a[i].y;
		sort(a,a+n,cmp);
		int sum = 1;
		for(int i=1;i<n;i++)
		{
			if(a[i].x>a[i-1].y) sum++;
			else a[i].y = min(a[i].y,a[i-1].y);
		}	
		cout<<sum<<endl;
	} 
}*/
/*
此题 思路是这样的  按照左端点 依次从小到大排序  然后贪心的时候 比较当前的左端点值与前一个右端点的值的  如果大于它 证明无法重合 总量加1
如果小于 则证明有重合区间 不需要加一 但要把当前的右端点值改为 当前与前一个右端点的值两者的最小值 因为 如果你要判断当前点的下一个点的话 因为当前点已经与
前一个点有重合部分了 但重合的部分的有右端点值肯定是当前点与前一个点的右端点的最小值 所以要判断当前点的后一个点是否与当前点重合 那么是判断与前面的重合区间是否重合
而不是与当前点代表的区间重合 这里要着重注意 
*/
struct node {
    int x, y;
};
struct node a[108];

bool cmp(struct node a, struct node b) {
    return a.y < b.y;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        sort(a, a + n, cmp);
        int sum = 1;
        int tempRight = a[0].y;
        for (int i = 1; i < n; i++) {
            if (a[i].x > tempRight) {
                sum++;
                tempRight = a[i].y;
            }
        }

        printf("%d\n", sum);
    }
}
/*
根据此题的两个方法 可得 贪心之前的组织数据方式 排序 按哪种方式排序不是唯一 重要的是排序的作用 第一种方式排序按左端点排序 因为求出各个区间覆盖的区域 仅仅后一个左端点小于前一个右端点 这是不够的 如果
后一个的右端点小于前一个左端点 虽然也满足一个左端点小于前一个右端点 但实际上根本不会相交 但按照左端点从小到大排序 则不会出现这种情况 但在遍历过程中的注意点看上面注释 
第二种方式 的排序方式也是起到类似的效果 
*/





