#include<stdio.h>

int map[8][8];
int n;
int count;

// 2 �� 3 ��
void dfs(int row, int type) {
    /*����ڷŵ��� ������ֻ��һ�� ûɶ��˵��*/
    for (int i = 0; i < n; i++) {
        /*�޷��� ���Ѿ��Ź���*/
        if (map[row][i] == 0 || map[row][i] == 2) {
            continue;
        }
        int flag = 1;
        int y1 = i - 1;
        int y2 = i + 1;
        for (int j = row - 1; j >= 0; j--) {
            /*column*/
            if (map[j][i] == type) {
                flag = 0;
                break;
            }
            /*diagonal*/
            if (y1 >= 0 && map[j][y1] == type) {
                flag = 0;
                break;
            }
            y1--;
            if (y2 < n && map[j][y2] == type) {
                flag = 0;
                break;
            }
            y2++;
        }

        if (flag) {
            map[row][i] = type;
            /*�����ŵ�ǰ(��)���� �������(��)���� ��ʼ�ں�*/
            if (row < n - 1) {
                dfs(row + 1, type);
            } else {
                /*���װ���ʱ ��ʼ�ں� ���ڰ���ʱ ˵��������*/
                if (type == 2) {
                    dfs(0, 3);
                } else {
                    count++;
                }
            }
            map[row][i] = 1;//��ԭ
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    count = 0;
    dfs(0, 2);
    printf("%d\n", count);
}
/*
˼·��ע��
��ʵ����ֱ������ ������پ������� ����Ϊ����ֻ���԰�һ�� ���� �оͲ���Ҫ��� ����Ҳ���жϵݹ��������
��֮ �ܾ��� 
*/ 

