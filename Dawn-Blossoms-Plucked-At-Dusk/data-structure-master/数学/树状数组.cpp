#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int lowBit(int n) {
    return n - (n & (n - 1));
}

void update(int n, int i, int v, int *a) {
    for (int k = i; k <= n; k += lowBit(k)) {
        a[k] += v;
    }
}

int getSum(int *a, int i) {
    int sum = 0;
    for (int k = i; k >= 1; k -= lowBit(k)) {
        sum += a[k];
    }
    return sum;
}

int main() {
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int c[9];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 8; i++) {
        update(9, i + 1, a[i], c);
    }

    for (int i = 0; i < 9; i++) {
        cout << c[i] << " ";
    }
}
/**
��״���������������͵�����
һ��ⷨ�������и�����a[11](0��λ����Ԫ��)
��ά��һ������c[11](0��λ����Ԫ��) c[i]��ʾǰi��a����Ԫ��֮�ʹ�С ���ô˷������������ʱ�ɽ���ʱ�临�Ӷ�
�����a������� ��c������Ӧ��Ҳ��Ҫ���� ʱ�临�Ӷ�Ϊ���Լ���

��״������Ϊ����
c1 = a1 
c2 = a1 + a2
c3 = a3
c4 = a1 + a2 + a3 + a4
c5 = a5
c6 = a5 + a6
�Դ�����
�����Ĺ���Ϊ c[i] �б���aiΪ��β  ����Ϊ2^k(kλi�Ķ�������ʽ �ӵ�λ��ʼ��0�ĸ�������ĩβ0�ĸ�����Ҳ����˵�Ǵ�ĩβ�� ��һ��1��λ���������ʮ����ֵ) ���Զ���һ������lowbit(i)���2^k 
���a�����ĳԪ�س��ָ��� ��a[i]���ָ��� ��c[i]�϶�Ҫ����  c[i + lowbit(i)], c[i + lowbit(i) + lowbit(i + lowbit(i)) ]ҲҪ���� ���Ӷȱ�Ϊ������
����ǰn���� ����ǰi���ĺ� ��Ϊc[i] + c[i - lowbit(i)] + .....�Դ����� ����ֵ�������1 (0��Ϊ��������) ҲΪ������
��������ɵ�Ҳͦ�ŵ� 
*/
