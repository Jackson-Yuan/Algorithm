#include<stdio.h>
#include<string.h>

char a[101];
int dp[101][101];
int n;
int max = 9999999999;

void clean() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
}

bool match(char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']')) return true;
    else return false;
}

int min(int a, int b) {
    if (a > b) return b;
    else return a;
}

void solve() {
    clean();
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = max;
            if (match(a[i], a[j])) dp[i][j] = dp[i + 1][j - 1];
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
}

int main() {
    int count;
    scanf("%d", &count);
    getchar();
    while (count--) {
        scanf("%s", a);
        n = strlen(a);
        solve();
        printf("%d\n", dp[0][n - 1]);
    }
}
/*״̬����dp[i][j] ��i��j����С����������
״̬ת�� �����βһ������β����һ��������ַ����������������ַ� �����ΪAB�����֣�ΪAB��������ӣ�������i��j��Ѱ�ҷָ�㣩 
�ر�ע�⣬��ʼ��dp��ʱ ���i>j��0 i=j��1��dp˳��һ���Ǵ��Ѿ���ʼ���õ������п�ʼ ���ۻ� 
*/
