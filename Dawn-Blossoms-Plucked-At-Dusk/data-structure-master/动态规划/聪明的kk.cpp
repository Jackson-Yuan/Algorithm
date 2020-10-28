#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int map[21][501];

int main() {
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int a = -1;
            int b = -1;
            if (i - 1 >= 0 && map[i][j] + map[i - 1][j] > map[i][j]) {
                a = map[i][j] + map[i - 1][j];
            }

            if (j - 1 >= 0 && map[i][j] + map[i][j - 1] > map[i][j]) {
                b = map[i][j] + map[i][j - 1];
            }
            if (a > b) map[i][j] = a;
            else map[i][j] = b;
        }
    }

    printf("%d\n", map[n - 1][m - 1]);
}
/*
����Ϊ��̬�滮 ԭ����� ��Ϊֻ�����»������� ���Զ�̬�滮ʱ
ȷ����ά����ÿ��������ֵ��ΪС��Ե����λ�õ����ֵ
����ȷ���ö�̬�滮����ı���˳��
���α����ж� ��ǰλ�� �Ǵ��������Ĵ� ���Ǵ��������Ĵ�
����ӡ��������� 
*/
