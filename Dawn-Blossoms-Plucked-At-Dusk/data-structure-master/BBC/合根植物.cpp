/**
��������
����w�����һ����ֲ԰�����ֳ� m * n ��С���ӣ���������m�У��ϱ�����n�У���ÿ������������һ��ϸ�ֲ�
��������ֲ���и��ص㣬���ĸ����ܻ������ϱ�����������չ���Ӷ�����һ�����ӵ�ֲ��ϳ�Ϊһ�塣


����������Ǹ�������ЩС���Ӽ������������������˵�����԰��һ���ж�����ϸ�ֲ����
�����ʽ
������һ�У���������m��n���ÿո�ֿ�����ʾ���ӵ�������������1<m,n<1000����
����������һ�У�һ������k����ʾ���滹��k������(0<k<100000)
����������k�У�������������a��b����ʾ���Ϊa��С���Ӻͱ��Ϊb��С���Ӻϸ��ˡ�


�������ӵı��һ��һ�У����ϵ��£������ұ�š�
�������磺5 * 4 ��С���ӣ���ţ�
����1 2 3 4
����5 6 7 8
����9 10 11 12
����13 14 15 16
����17 18 19 20
��������
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
�������
5
*/
#include<iostream>
#include<string.h>

using namespace std;
int bound[1000000];
int count[1000000];

int find(int location) {
    int son = location;
    /**Ѱ�Ҹ�*/
    while (location != bound[location]) {
        location = bound[location];
    }

    /**·��ѹ���㷨 ���Բ�д*/
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
���Ⲣ�鼯�Ľⷨ
��ν���鼯����
�൱�� ����һ�����������ݹ�Ϊһ�� Ȼ����ѡ��������Ϊ���� �������� �Ѹ���Ϊ����
����������ʽ a[i] = j  ��ʾi�ĸ�Ϊj  ��a[i] = i ���ʾ�ܸ�

�����編����  �������� ����ֱ���γ��� ����join��������  find����Ѱ�Ҹ�
���Ӽ���


�·�����dfs���� ��ϧֱ�ӳ�ʱ 
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
