#include<iostream>

using namespace std;
int a[100];
int n;

void swim(int k) {//上浮时可能会引起连锁反应
    while (k > 1 && a[k / 2] < a[k]) {
        int temp = a[k / 2];
        a[k / 2] = a[k];
        a[k] = temp;
        k = k / 2;
    }
}

void sink(int k) {
    while (2 * k <= n) {//下沉时可能会引起连锁反应
        int j = 2 * k;
        if (j + 1 <= n && a[j] < a[j + 1]) {
            j++;//找出索引k的父节点的两个子节点的最大值
        }
        if (a[k] > a[j]) break;
        int temp = a[k];
        a[k] = a[j];
        a[j] = temp;
        k = j;
    }
}

void insert(int value) {//插入数组末尾 并考虑是否能上浮
    n++;
    a[n] = value;
    swim(n);
}

int deleteMax() {//删除最大数 降末尾数放在根处 并考虑是否下沉
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
