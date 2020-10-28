/**
��һ����˵������������Ϸ��
�硾ͼ1.png���������Ҫ����9��9�����ϵ���֪���֣����������ʣ��ո�����֣�������ÿһ�С�ÿһ�С�ÿһ��ͬɫ�Ź��ڵ����־���1-9�����ظ���

�����Ĵ𰸶���Ψһ�ģ����ԣ������Ҳ��Ϊ�޽⡣

��ͼ�����־�˵�Ƿ�����ѧ�һ���3���µ�ʱ����Ƴ����Ľ��ѵ���Ŀ�����Ի�ʹ�ü������̵�����˵���������練���ˡ�

�����Ҫ���������������Ŀ���������������Ψһ�⡣���Ǳ�֤������֪���ݵĸ�ʽ���ǺϷ��ģ�������Ŀ��Ψһ�Ľ⡣

��ʽҪ������9�У�ÿ��9�����֣�0����δ֪����������Ϊ��֪��
���9�У�ÿ��9�����ֱ�ʾ�����Ľ⡣

���磺
���루��ͼ����Ŀ����
005300000
800000020
070010500
400005300
010070006
003200080
060500009
004000030
000009700

����Ӧ�������
145327698
839654127
672918543
496185372
218473956
753296481
367542819
984761235
521839764

�����磬���룺
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400

����Ӧ�������
812753649
943682175
675491283
154237896
369845721
287169534
521974368
438526917
796318452
*/
#include<stdio.h>
#include<iostream>

using namespace std;
int map[9][9];

bool judge(int x, int y, int value) {
    bool token = true;
    /**check row*/
    for (int i = 0; i < 9; i++) {
        if (i != y) {
            if (map[x][i] == 0) continue;
            else if (map[x][i] == value) {
                token = false;
                break;
            }
        }
    }
    if (!token) return false;
    /**check column*/
    for (int i = 0; i < 9; i++) {
        if (i != x) {
            if (map[i][y] == 0) continue;
            else if (map[i][y] == value) {
                token = false;
                break;
            }
        }
    }
    if (!token) return false;

    int tmp = x / 3;
    int startX = tmp * 3;
    tmp = y / 3;
    int startY = tmp * 3;
    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (i != x || j != y) {
                if (map[i][j] == 0) continue;
                else if (map[i][j] == value) {
                    token = false;
                    break;
                }
            }
        }
    }

    if (!token) return false;

    return token;
}

void dfs(int x, int y) {
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    if (map[x][y] != 0) {
        if (y + 1 < 9) dfs(x, y + 1);
        else dfs(x + 1, 0);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (judge(x, y, i)) {
                map[x][y] = i;
                if (y + 1 < 9) dfs(x, y + 1);
                else dfs(x + 1, 0);
                map[x][y] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
        }
    }
    cout << endl;

    dfs(0, 0);
}
/**
���ѵľ����� ����˼· dfs���������� ���ͳһ�ж� ��ʵ����������ѧ
���Ǳ�дһ��judge���������м�֦��������������ʱ��
�������ع�һ��ö�ٹ���
�� 0 0 ��ʼ ��map[0][0]������0ֱ����һ����
��Ϊ0 ��ʼ 1 ~ 9ö�� ����judge�����жϵ�ǰ������ܷ��
����һ������� 1 ~ 9��û�ܳɹ� �˻���һ��������ѡ������һ���㻹���� �˻���һ�����Դ�����(���ǵ��˻�ʱ map�û�ԭΪ0����������) 
*/
