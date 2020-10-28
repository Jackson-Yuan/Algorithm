#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int w[100];
int v[100];
int dp[100][100];

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
            dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
/**
��01������ͬ 01����ÿ��ֻ�ܷ�һ�� ������Ҫת�Ƶ�dp[i - 1]��
��ÿ����ȫ�����������޷� ����ת�Ƶ�dp[i]�м��� 
*/
