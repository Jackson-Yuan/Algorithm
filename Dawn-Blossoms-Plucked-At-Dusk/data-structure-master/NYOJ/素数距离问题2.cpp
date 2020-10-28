#include<iostream>
#include<math.h>

using namespace std;

bool panduan(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if ((n % i) == 0) return false;
    }
    return true;
}

int main() {
    int n, num, i, j;
    cin >> n;
    while (n--) {
        cin >> num;
        if (num == 1) {
            cout << "2 1" << endl;
            continue;
        }
        for (i = num; !panduan(i); i--);
        for (j = num; !panduan(j); j++);
        if ((num - i) < (j - num)) {
            cout << i << " " << (num - i) << endl;
        }
        if ((num - i) > (j - num)) {
            cout << j << " " << (j - num) << endl;
        }
        if ((num - i) == (j - num)) {
            cout << i << " " << (num - i) << endl;
        }
    }
}
