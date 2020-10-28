#include<iostream>

using namespace std;
int a[100];
int n;

void swim(int k) {//�ϸ�ʱ���ܻ�����������Ӧ
    while (k > 1 && a[k / 2] < a[k]) {
        int temp = a[k / 2];
        a[k / 2] = a[k];
        a[k] = temp;
        k = k / 2;
    }
}

void sink(int k) {
    while (2 * k <= n) {//�³�ʱ���ܻ�����������Ӧ
        int j = 2 * k;
        if (j + 1 <= n && a[j] < a[j + 1]) {
            j++;//�ҳ�����k�ĸ��ڵ�������ӽڵ�����ֵ
        }
        if (a[k] > a[j]) break;
        int temp = a[k];
        a[k] = a[j];
        a[j] = temp;
        k = j;
    }
}

void insert(int value) {//��������ĩβ �������Ƿ����ϸ�
    n++;
    a[n] = value;
    swim(n);
}

int deleteMax() {//ɾ������� ��ĩβ�����ڸ��� �������Ƿ��³�
    int max = a[1];
    a[1] = a[n];
    n--;
    sink(1);
    return max;
}

int main() {
    n = 5;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << deleteMax() << endl;
    cout << a[1] << endl;
    insert(10);
    cout << a[1] << endl;
}
