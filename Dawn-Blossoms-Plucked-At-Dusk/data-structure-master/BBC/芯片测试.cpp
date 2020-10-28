#include<stdio.h>

int result[20][20];
int show[20];
int n;
int index;
int count;

void dfs(int index) {
    if (index == n) {
        if (count < n - count) return;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (show[i] == 1 && show[j] == 1 && i != j) {
                    if (result[i][j] != 1) return;
                }

                if (show[i] == 1 && show[j] == 0 && i != j) {
                    if (result[i][j] != 0) return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (show[i] == 1) printf("%d ", i + 1);
        }
        printf("\n");
        return;
    }
    show[index] = 0;
    dfs(index + 1);
    show[index] = 1;
    count++;
    dfs(index + 1);
    count--;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &result[i][j]);
        }
    }
    count = 0;
    dfs(0);
}
/*����˼· ����dfsʵ��ȫ���� ��ٳ�����оƬ�û���� Ȼ���ú�оƬ������оƬ������ ��������result���鲻һ�µĻ� ������ʧЧ
ͬʱ��Ҫ����ϸ�� �õĸ������ڻ��ĸ��� 

ͬʱ ����һ�ַ��� ��Ϊ�õ�оƬ�������ڻ���оƬ���� ���� һ��оƬ������оƬ����ʱ result[i][j] = 1 �������� ��Ϊ��оƬ(����iΪ������оƬ)
�뵽��� ��Ҳ�Ƿ� 
*/
