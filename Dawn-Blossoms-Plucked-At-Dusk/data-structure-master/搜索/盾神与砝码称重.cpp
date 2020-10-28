/**
��һ�죬���������������з�����һ����ƽ����  ����ƽ����֣���n����õ����룬����û�����롣����Ϊ���ķ����˷ܲ��ѣ�������׼��ȥ��һ���Լ��Ķ�����
��׼������m����Ʒȥ�ơ�������ǣ�����һ���  ֪����m����Ʒ�����������������뿴�������ƽ�ܲ��ܳƳ���Щ��Ʒ������
���Ƕ�����΢����1�����Ժ�;����������̫�����ˣ����ǾͶ������㡣 ���ݹ�ģ��Լ�� 1< =n< =24,  1< =m< =10. 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;
int n, m, flag;
int sum[24];
int fm[24];
int wp[24];

void dfs(int difference, int index) {/**��һ������Ʒ��������֮�͵Ĳ�ֵ�� ѡȡ������*/
    if (flag == 1) return;
    if (abs(difference) > sum[index]) return;
    if (difference == 0 || abs(difference) == sum[index]) {
        flag = 1;
        return;
    }
    if (index < 0) return;
    dfs(difference - fm[index], index - 1);
    dfs(difference, index - 1);
    dfs(difference + fm[index], index - 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> fm[i];
        if (i > 0) {
            sum[i] = sum[i - 1] + fm[i];
        } else sum[i] = fm[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> wp[i];
    }

    for (int i = 0; i < m; i++) {
        flag = 0;
        int target = wp[i];
        dfs(target, n - 1);
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
/**
����������� ����Ǹ����� ���������������������Ʒ��С���бȽ�
�������������� ����Ĺ���90%������ �����ֱ�ӳ�ʱ  ��ԭ������������ʽ��ͬ 
�����������ʽ ��ʵ�������ȫ������ʽ ����������
�����������ÿ������İڷſ����������� ������ ������Ʒ���� ������Ʒһ�� �����������
��������� ��ôҲ����ֻ�ܹ�һ��Ĳ��������� ����sum���������Ż������� ����sum���鱣��ǰi������
�������� ������������ �жϲ�ֵ�Ƿ����ʣ�������֮�� ������϶������� ������ ��Ҳ���ؼ������� �϶����� �������� ���Ż������� 
*/
/**int target, flag;
int n, m;
int fm[26];
int wp[26];
int visited[24];
void dfs(int sum){
	if(flag == 1) return;
	
	if(sum == target){
		flag = 1;
		return;
	}
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0){
			visited[i] = 1;
			dfs(sum + fm[i]);
			if(sum >= fm[i]){
				dfs(sum - fm[i]);
			}
			visited[i] = 0;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> fm[i];
	}
	for(int i = 0 ; i < m ; i++){
		cin >> wp[i];
	}
	for(int i = 0 ; i < m ; i++){
		memset(visited,0,sizeof(visited));
		target = wp[i];
		flag = 0;
		dfs(0);
		if(flag == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}*/
