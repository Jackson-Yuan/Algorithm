#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define maxn 1010
using namespace std;
typedef long long ll;

/*
����Ŀ
ÿ�д���һ������һ����8λ�������� 0��ʾ�� 1��ʾī�� ��*
����&����� ��1�������㣬��8���ֽ�ÿһ���ֽ���֮���������㣬��1
����1 ��0����0  ÿ����һ�κ�������λ ����֮���бȽϣ�ѭ��8�˼��� 

*/
int main() {
    int a[100][100];
    int x;
    int t = 10;
    while (t--) {
        memset(a, 0, sizeof(a));
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            cin >> x;
            for (int j = 7; j >= 0; j--) {
                a[ans][j] = (x & 1);   //ȡ��λ
                x = x >> 1;         //��λ
            }
            ans++;
        }
        //��ӡ������
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 8; j++) {
                if (a[i][j]) cout << "*";
                else { cout << " "; }
            }
            if (i % 2 == 1) cout << endl;  //����16λ��ӡ
        }
    }
    return 0;
}

