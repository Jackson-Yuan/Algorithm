#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;

void show();

int sum;
int n;
int map[11][11];
int visited[11];

void dfs(int i, int target) {
    if (visited[i] == 1) return;
    if (i == target) {
        sum++;
    }
    visited[i] = 1;
    cout << i << "�����" << endl;
    for (int j = 1; j <= n; j++) {
        if (map[i][j] = 1 && visited[j] == 0) {
            dfs(j, target);
        }
    }
    visited[i] = 0;
    cout << i << "���ȡ��" << endl;
}

/*void dfs(int i,int target){
	if(visited[i] == 1) return;
	if(i == target){
		sum++;
	}
	visited[i] = 1;
	cout<<i<<"�����"<<endl; 
	for(int j = 1 ; j<=n ; j++){
		if(map[i][j] = 1 && visited[j] == 0){
			dfs(j,target);
		}
	}
}*/
void show() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", visited[i]);
    }
    printf("\n");
}

int main() {
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    sum = 0;
    int r;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < r; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    dfs(1, 3);
    printf("%d", sum);
}
/*
����������������dfsд�����������ڷ��ʱ�ǵĲ��� һ���Ƿ���֮���ٻ�ԭ������һ���Ƿ���֮��ԭ
���ߵĲ������ ��������1 2 3������ ��β��ͨ  ������ٻ�ԭ�Ļ� ��ôֻ����1-2,2-3,3-1�������˳�������ԭ ����1-2,2-3,3-1��1-3,3-2,2-1������˳�� 
���������ַ��ʱ�Ǵ����ַ� ��֮��Ҫʹ���ڵ�ǰ����dfs·���� �߹��ĵ㶼���뱻����� ������û�б��,����ݹ��Ҳ������ڣ���ѭ��. 
*/
