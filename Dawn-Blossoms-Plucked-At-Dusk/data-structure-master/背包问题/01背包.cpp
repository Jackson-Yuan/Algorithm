#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
int w[100];
int v[100];
int dp[100][100];//ǰi����Ʒ���Ϊj������ֵ 
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }
}
/**
ÿ����Ʒ��������ѡ�� Ҫô�� Ҫô����
���ô˹��� ���Խ��ж�̬�滮 
*/
