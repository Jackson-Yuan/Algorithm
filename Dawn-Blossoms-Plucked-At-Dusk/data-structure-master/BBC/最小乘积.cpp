#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int a[10];
int b[10];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n, cmp);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] * b[i];
        }
        cout << sum << endl;
    }

}
/**
�����޻���˵ �������� ����ͬ�±�˻�֮��Ϊ��С 
�����������������С����һ���ŵ� �����и��������������� ����
��ʵ �ٸ����� a����Ϊ c,d d > c  b����ҲΪ c,d d>c 
��С����Ļ� Ϊ  c^2 + d ^2  �����ŵĻ�Ϊ2dc  ǰ�ߴ��ڵ��ں��� ���� 
*/
