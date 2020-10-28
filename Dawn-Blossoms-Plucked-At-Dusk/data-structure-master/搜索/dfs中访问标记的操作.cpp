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
    cout << i << "被标记" << endl;
    for (int j = 1; j <= n; j++) {
        if (map[i][j] = 1 && visited[j] == 0) {
            dfs(j, target);
        }
    }
    visited[i] = 0;
    cout << i << "标记取消" << endl;
}

/*void dfs(int i,int target){
	if(visited[i] == 1) return;
	if(i == target){
		sum++;
	}
	visited[i] = 1;
	cout<<i<<"被标记"<<endl; 
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
上述代码中有两个dfs写法，区别在于访问标记的操作 一个是访问之后不再还原，另外一个是访问之后还原
两者的差别在于 比如我有1 2 3三个点 首尾连通  如果不再还原的话 那么只会有1-2,2-3,3-1这个访问顺序，如果还原 择优1-2,2-3,3-1与1-3,3-2,2-1的两种顺序 
无论是那种访问标记处理手法 总之都要使得在当前这条dfs路径上 走过的点都必须被标记上 更不能没有标记,否则递归找不到出口，死循环. 
*/
