#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

bool judge(int value) {
    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    int start = 2;
    int sum = 1;
    while (1) {
        if (judge(start)) {
            count++;
            sum %= 50000;
            int temp = start;
            temp %= 50000;

            sum *= temp;
            sum %= 50000;

        }
        start++;
        if (count == n) break;
    }

    cout << sum << endl;
}
/**
筛素数算法 取模等价公式复习 
*/
