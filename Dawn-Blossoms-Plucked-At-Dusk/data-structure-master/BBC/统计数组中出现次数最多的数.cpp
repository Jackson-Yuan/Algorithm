#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
int a[100];

int main() {
    int n;
    int count, countMax, target;
    cin >> n;

    if (n <= 0) return 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    count = 1;
    countMax = 1;
    target = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > countMax) {
            countMax = count;
            target = a[i];
        }
    }

    cout << target << endl;
}
/**
���������㷨ǰ������Ϊ����Ϊ��С�����������У�Ȼ�����������������ıȽϣ���ͬ�ʹ�����һ ������ͬ˵����������ͳ�ƴ��������¿�ʼͳ�ƣ���ͳ�Ʊ���Ϊ1��ͬʱͳ�ƴ�����Ҫ�����ͳ�ƴ������бȽϣ��������� 
��Ϊ�Ѿ�������������ͬ�����϶��������İ�����һ����Ҳ�����еĹؼ�
�������е��ô��� 
*/
