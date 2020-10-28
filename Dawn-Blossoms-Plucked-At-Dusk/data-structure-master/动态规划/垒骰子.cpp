/**
��Ŀ������
��ʥatm�����������������ӣ����ǰ�����һ��������һ���ϱߣ���������ŤŤ��Ҫ�ݳɷ����塣 
�������ڹ۲죬atm �������ȶ����ӵİ��أ���Щ���ֵ������Żụ���ų⣡ ���������淶һ�����ӣ�1 �Ķ����� 4��2 �Ķ����� 5��3 �Ķ����� 6�� 
������ m �黥������ÿ���е����������ֵ��������һ�����ӾͲ����ȶ�����������  atm�����һ���ж����ֲ�ͬ�Ŀ��ܵ������ӷ�ʽ��
���������ӷ�ʽ��ͬ�����ҽ��������ַ�ʽ�ж�Ӧ�߶ȵ����ӵĶ�Ӧ���ֵĳ�����ͬ�� ���ڷ��������ܹ��࣬�����ģ 10^9 + 7 �Ľ����  
��ҪС���� atm ����������Ŷ��  
�������ʽ�� 
��һ���������� n m n��ʾ������Ŀ 
������ m �У�ÿ���������� a b ����ʾ a �� b ���ֲ��ܽ�����һ��  
�������ʽ�� 
һ��һ��������ʾ��ģ 10^9 + 7 �Ľ����  
���������롹 
 2 1
 1 2  
����������� 544  
�����ݷ�Χ�� 
���� 30% �����ݣ�n <= 5 ���� 60% �����ݣ�n <= 100 
���� 100% �����ݣ�0 < n <= 10^9, m <= 36   
��ԴԼ���� 
��ֵ�ڴ����� < 256M CPU����  < 2000ms   
���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�  
���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣  
ע��: main������Ҫ����0 
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯���� ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���  
�ύʱ��ע��ѡ���������ı��������͡�
*/
#include<iostream>
#include<string.h>
#include<map>

using namespace std;

long long pow(long long a, long long b) {
    long long base = a;
    long long sum = 1;
    while (b) {
        if (b & 1 == 1) sum *= base;
        base *= base;
        b = b >> 1;
    }

    return sum;

}//a^b
bool conflict[7][7];
map<int, int> mm;
int dp[101][7];//��i�� ����j���� 
void init() {
    mm[1] = 4;
    mm[2] = 5;
    mm[3] = 6;
    mm[4] = 1;
    mm[5] = 2;
    mm[6] = 3;
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    memset(conflict, 0, sizeof(conflict));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }

    for (int i = 1; i <= 6; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i][j] = 0;
            for (int k = 1; k <= 6; k++) {
                if (!conflict[mm[k]][j]) dp[i][j] += dp[i - 1][k];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += dp[n][i];
    }

    cout << ans * pow(4, n) << endl;
}
/**
/**#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int count;
int n;
int sum;
bool conflict[7][7];
int num[7];
void dfs(int index, int pre){
	if(index == n){
		count++;
		count %= 1000000007;
		return;
	}
	
	for(int i = 1 ; i <= 6 ; i++){
		if(index == 0){
		   dfs(index + 1, i);
		}else{
			if(!conflict[num[pre]][i]){
				dfs(index + 1, i);
			}
		}
	}
}
int main(){
	int m;
	cin >> n >> m;
	num[1] = 4;
	num[2] = 5;
	num[3] = 6;
	num[4] = 1;
	num[5] = 2;
	num[6] = 3;
	sum = 1;
	for(int i = 0 ; i < n ; i++){
		sum *= 4;
	}
	memset(conflict, 0, sizeof(conflict));
	for(int i = 0 ; i < m ; i++){
		int a, b;
		cin >> a >> b;
		conflict[a][b] = true;
		conflict[b][a] = true;
	}
	
	count = 0;
	dfs(0, 0);
	cout << count << endl;
	cout << count * sum << endl;
}*/
/**
����ע�Ͳ��ִ���Ϊ�������� ˼·������� ���Ǽ򵥵ı����������аڷ���� ��һ������6�ַ���  �Ժ�İڷŶ�Ҫ�����Ƿ񻥳�
���˷�����ֱ�ӳ�ʱ
��������˼· һ������ֵ ������ ��̬�滮 ̰��
����̰�Ŀ϶�����ʵ Ӧ���ö�̬�滮
������άdp���� �б�ʾ�ݵĲ������б�ʾ�ĸ��泯��
����Ȼ �ڵ�һ��ʱ j�����������Ϊ1  ��������1֮�� ÿ��j�����������һ��������(�ų������泯�ϵ�����������ۼӼ���) 
*/
