#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
int map[9][9];
int flag;

/*�жϴ����ڴ��У����У���3*3��С������û���ظ�����*/
bool judge(int number, int x, int y) {
    for (int i = 0; i < 9; i++) {
        if (map[x][i] == number) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (map[i][y] == number) return false;
    }

    int a = x / 3;
    a = 3 * a;
    int b = y / 3;
    b = 3 * b;
    for (int i = a; i < a + 3; i++) {
        for (int j = b; j < b + 3; j++) {
            if (map[i][j] == number) return false;
        }
    }

    return true;
}

void dfs(int x, int y) {
    if (flag == 1) return;
    if (x == 9 && y == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        flag = 1;
        return;
    }
    if (map[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (flag == 1) {
                return;
            }
            if (judge(i, x, y)) {
                map[x][y] = i;
                if (y + 1 == 9) dfs(x + 1, 0);
                else dfs(x, y + 1);
                map[x][y] = 0;//��ԭ�����ݵ���һ����ǰ�軹ԭ���������һ�����ٴΰݷô˵�ʱ������ �����˴����ǽ��鸳ֵһ�Σ���ԭһ�Σ��Ա���judge�����Ƚ� ,���������ע�ʹ��봦

            }
        }
        /*map[x][y] = 0;*/

    } else {
        if (y + 1 == 9) dfs(x + 1, 0);
        else dfs(x, y + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        flag = 0;
        dfs(0, 0);
    }
}
/*�����õ��ִ���˼·���е� ����ֱ�ӱ���dfs���������� �ж��Ƿ���Ч
�����³�ʱ��û��ϸ�룬ϸ��Ļ� �������ж��� Ӧ�ñ�дһ��judge������judge�������ж�3*3������ַ����ó���������������ҵ�9��3*3�����׸�Ԫ�ص�����
ͬʱ��dfs������ ��һ����֮ǰ����Ҫ�ж�һ�� �ٸ�ֵ
ͬʱ��ֵ�Ļ�ԭλ��ҲҪϸϸ����(������map[x][y] = 0) ��֮ ��һ������ 
*/
