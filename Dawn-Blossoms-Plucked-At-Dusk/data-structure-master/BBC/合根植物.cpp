/**
问题描述
　　w星球的一个种植园，被分成 m * n 个小格子（东西方向m行，南北方向n列）。每个格子里种了一株合根植物。
　　这种植物有个特点，它的根可能会沿着南北或东西方向伸展，从而与另一个格子的植物合成为一体。


　　如果我们告诉你哪些小格子间出现了连根现象，你能说出这个园中一共有多少株合根植物吗？
输入格式
　　第一行，两个整数m，n，用空格分开，表示格子的行数、列数（1<m,n<1000）。
　　接下来一行，一个整数k，表示下面还有k行数据(0<k<100000)
　　接下来k行，第行两个整数a，b，表示编号为a的小格子和编号为b的小格子合根了。


　　格子的编号一行一行，从上到下，从左到右编号。
　　比如：5 * 4 的小格子，编号：
　　1 2 3 4
　　5 6 7 8
　　9 10 11 12
　　13 14 15 16
　　17 18 19 20
样例输入
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17
样例输出
5
*/
#include<iostream>
#include<string.h>

using namespace std;
int bound[1000000];
int count[1000000];

int find(int location) {
    int son = location;
    /**寻找根*/
    while (location != bound[location]) {
        location = bound[location];
    }

    /**路径压缩算法 可以不写*/
    while (son != location) {
        int temp = bound[son];
        bound[son] = location;
        son = temp;
    }
    return location;
}

void join(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) {
        bound[xx] = yy;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        bound[i] = i;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    memset(count, 0, sizeof(count));
    for (int i = 1; i <= n * m; i++) {
        count[find(i)] = 1;
    }
    int sum = 0;

    for (int i = 1; i <= n * m; i++) {
        sum += count[i];
    }

    cout << sum << endl;
}
/**
此题并查集的解法
所谓并查集就是
相当于 符合一个特征的数据归为一类 然后用选个数据作为代表 类似于树 把根当为代表
利用数组形式 a[i] = j  表示i的根为j  若a[i] = i 则表示总根

此题如法炮制  由于连根 可以直接形成树 利用join函数连接  find函数寻找根
连接即可


下方还有dfs样例 可惜直接超时 
*/















/**#include<iostream>
#include<algorithm>
#include<map> 
using namespace std;
int visited[1000][1000];
int countValue;
int n, m;
map<string, int> token;
string intToString(int x, int y){
	char value[10];
	int index = 0;
	while(x){
		value[index] = '0' + x % 10;
		x /= 10;
		index++;
	}
	
	while(y){
		value[index] = '0' + y % 10;
		y /= 10;
		index++;
	}
	
	int left = 0;
	int right = index - 1;
	while(left < right){
		char temp = value[left];
		value[left] = value[right];
		value[right] = temp;
		left++;
		right--;
	}
	
	value[index] = '\0';
	string result = value;
	return result;
} 
void dfs(int x, int y){
	visited[x][y] = 1;
	
	if(x - 1 >= 0 && visited[x - 1][y] == 0 && token[intToString(x * m + y + 1, (x - 1) * m + y + 1)] == 1) dfs(x - 1, y);
	if(x + 1 < n && visited[x + 1][y] == 0 && token[intToString(x * m + y + 1, (x + 1) * m + y + 1)] == 1)  dfs(x + 1, y);
	if(y + 1 < m && visited[x][y + 1] == 0 &&  token[intToString(x * m + y + 1, x * m + y + 2)] == 1)  dfs(x, y + 1);
	if(y - 1 >= 0 && visited[x][y - 1] == 0 && token[intToString(x * m + y + 1, x * m + y)] == 1)  dfs(x, y - 1);
}
int main(){
	int k;
	cin >> n >> m;
	cin >> k;
	for(int i = 0 ; i < k ; i++){
		int a, b;
		cin >> a >> b;
		token[intToString(a, b)] = 1;
		token[intToString(b, a)] = 1;
	}
	countValue = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(visited[i][j] == 0){
				countValue++;
				dfs(i, j);
			}
		}
	}
	
	cout << countValue << endl;
}*/
