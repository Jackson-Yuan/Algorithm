#include<stdio.h>
#include<string.h>

int c[1000][1000];
char str1[1000];
char str2[1000];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", str1);
        scanf("%s", str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        c[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            c[i][0] = 0;
        }

        for (int i = 1; i <= len2; i++) {
            c[0][i] = 0;
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - 1];
                }
            }
        }

        printf("%d\n", c[len1][len2]);
    }
}
/*
���⾭�䶯̬�滮 ���������Ӵ� �ó����½���
a0a1a2a3a4.......an-1
b0b1b2b3b4.......bm-1
��z0z1z2z3z4.......zk-1Ϊ�������������
��an-1 = bm-1
��zk-1 = an-1 = bm-1
�ó�z0z1......zk-2Ϊa0a1....an-2, b0b1b2b3b......bn-2�������� 

���an-1 ��= bm-1
��ôz0z1.....zk-1 Ϊa0.....an-2, b0........bn-1�������� ���� a0........an-1, b0.......bn-2��������
ȡ�����г���

�����һƥ�� ���������� ͨ�����������������
��̬�����ÿһ�������Ž�
��̰�ĵ�����
̰�ĵ����Ž�һ��������һ�������Ž�
��̬�滮�����Žⲻһ��������һ�������Ž� ������֮ǰĳ���ֲ����Ž� 
*/
