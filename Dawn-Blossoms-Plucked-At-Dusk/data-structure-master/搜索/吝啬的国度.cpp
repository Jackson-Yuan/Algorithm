#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
typedef struct node {
    int data;
    node *next;
} node;
int n;
node nodes[1000001];
int visited[1000001];
int previous[100001];

void dfs(node location) {
    visited[location.data] = 1;
    for (node *p = location.next; p != 0; p = p->next) {

        if (!visited[p->data]) {
            previous[p->data] = location.data;
            dfs(nodes[p->data]);
        }
    }
}

void clear() {
    for (int i = 0; i <= n; i++) {
        node *p = nodes[i].next;
        while (p) {
            node *temp = p->next;
            delete p;
            p = temp;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int location;
        scanf("%d %d", &n, &location);
        memset(visited, 0, (n + 1) * sizeof(int));
        memset(previous, 0, (n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++) {
            nodes[i].data = i;
            nodes[i].next = 0;
        }
        for (int i = 0; i < n; i++) {
            int start, end;
            scanf("%d %d", &start, &end);
            node *p = new node;
            p->data = end;
            p->next = nodes[start].next;
            nodes[start].next = p;
            node *pr = new node;
            pr->data = start;
            pr->next = nodes[end].next;
            nodes[end].next = pr;
        }

        dfs(nodes[location]);
        previous[location] = -1;
        for (int i = 1; i <= n; i++) {
            printf("%d", previous[i]);
            if (i != n) {
                printf(" ");
            } else printf("\n");
        }
        clear();

    }
}
/*
������Ҫ�����н�����������ӵ�Ĺ�ϵ��֯�� ������ʹ������ʮ������Ҳ����ʹ��vector����
���ű�dfs��ע�� ��ʼ�õ�dfs��һ����һ������� ����ֱ�ӳ�ʱ��Ӧ�þ�ִ��һ��ȫ���dfs��ÿ�����
ǰһ���㱣��������������ɽ�ʡ����ʱ�� 
*/
/*
����vector����
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int pre[100005];
vector<int>v[100005];
 
void dfs(int s)
{
	int i;
	for(i=0;i<v[s].size();i++)
	{
		if(pre[v[s][i]])
		    continue;
		pre[v[s][i]]=s;
		dfs(v[s][i]);
	}
}
int main()
{
	int m;
	int n,s;
	int a,b;
	int i,j;
	scanf("%d",&m);
	while(m--)
	{
		memset(v,0,sizeof(v));
		memset(pre,0,sizeof(pre));
		scanf("%d%d",&n,&s);
		pre[s]=-1;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(s);
		for(i=1;i<=n;i++)
		{
		    printf("%d",pre[i]);
		    if(i!=n)
		        printf(" ");
		    else
		        printf("\n");
		}
	}
	return 0;
}
 

*/ 


