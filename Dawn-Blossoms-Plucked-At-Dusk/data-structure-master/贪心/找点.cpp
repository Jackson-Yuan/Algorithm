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
���� ˼·��������  ������˵� ���δ�С��������  Ȼ��̰�ĵ�ʱ�� �Ƚϵ�ǰ����˵�ֵ��ǰһ���Ҷ˵��ֵ��  ��������� ֤���޷��غ� ������1
���С�� ��֤�����غ����� ����Ҫ��һ ��Ҫ�ѵ�ǰ���Ҷ˵�ֵ��Ϊ ��ǰ��ǰһ���Ҷ˵��ֵ���ߵ���Сֵ ��Ϊ �����Ҫ�жϵ�ǰ�����һ����Ļ� ��Ϊ��ǰ���Ѿ���
ǰһ�������غϲ����� ���غϵĲ��ֵ����Ҷ˵�ֵ�϶��ǵ�ǰ����ǰһ������Ҷ˵����Сֵ ����Ҫ�жϵ�ǰ��ĺ�һ�����Ƿ��뵱ǰ���غ� ��ô���ж���ǰ����غ������Ƿ��غ�
�������뵱ǰ�����������غ� ����Ҫ����ע�� 
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
���ݴ������������ �ɵ� ̰��֮ǰ����֯���ݷ�ʽ ���� �����ַ�ʽ������Ψһ ��Ҫ������������� ��һ�ַ�ʽ������˵����� ��Ϊ����������串�ǵ����� ������һ����˵�С��ǰһ���Ҷ˵� ���ǲ����� ���
��һ�����Ҷ˵�С��ǰһ����˵� ��ȻҲ����һ����˵�С��ǰһ���Ҷ˵� ��ʵ���ϸ��������ཻ ��������˵��С�������� �򲻻����������� ���ڱ��������е�ע��㿴����ע�� 
�ڶ��ַ�ʽ ������ʽҲ�������Ƶ�Ч�� 
*/





