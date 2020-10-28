#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
struct store {
    int location;
    int size;
    int value;
};
struct store a[100];

bool compare(struct store a, struct store b) {
    return a.value < b.value;
}

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        while (t--) {
            int k, e, n;
            scanf("%d%d%d", &k, &e, &n);
            for (int i = 0; i < n; i++) {
                int tempValue;
                scanf("%d%d%d", &a[i].location, &a[i].size, &tempValue);
                a[i].value = (e - a[i].location) + tempValue;
            }
            sort(a, a + n, compare);
            int min = 0;
            for (int i = 0; i < n; i++) {
                if (k > a[i].size) {
                    min += a[i].size * a[i].value;
                    k = k - a[i].size;
                } else {
                    min += k * a[i].value;
                    break;
                }
            }
            printf("%d\n", min);
        }
    }
}
/*
����������˸�����  �����ϸ�̰�ı�������һ�� ֻ��������ÿ���̵�feed�ĵ���ʱʱ����������ĵ��� ����Ҫ�����˷� ��������ϵ���
����������ϵ��۴�С�������� ����ѡȡҪ��feed�ļ����̼� ͬʱֵ��һ����� ���ܻ������� �����Ͳ��ǰ�˳������� ���ܻ����۷�·��
��ʵ���������� ����̰��ֻ��ѡȡҪ����̼� �������ʱ���ǰ�˳����� ̰��ֻ���ṩҪ����̼Ҽ��̼Ҷ�Ӧ�����feed����
����һ��ת�������� 
*/
