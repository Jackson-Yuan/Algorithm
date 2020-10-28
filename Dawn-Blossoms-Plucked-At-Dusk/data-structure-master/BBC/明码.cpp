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
此题目
每行代表一个数，一个数8位，二进制 0表示底 1表示墨迹 即*
利用&运算符 与1进行运算，若8个字节每一个字节与之进行与运算，若1
就是1 若0就是0  每进行一次后，向右移位 再与之进行比较，循环8此即可 

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
                a[ans][j] = (x & 1);   //取低位
                x = x >> 1;         //移位
            }
            ans++;
        }
        //打印出汉字
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 8; j++) {
                if (a[i][j]) cout << "*";
                else { cout << " "; }
            }
            if (i % 2 == 1) cout << endl;  //凑足16位打印
        }
    }
    return 0;
}

