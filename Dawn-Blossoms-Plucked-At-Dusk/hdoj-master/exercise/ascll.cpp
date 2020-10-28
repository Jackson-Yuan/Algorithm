/**
 * 输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    char a, b, c;
    while (cin >> a >> b >> c) {
        if (b < a) {
            if (b < c) {
                cout << b << " ";
                if (a < c) cout << a << " " << c << endl;
                else cout << c << " " << a << endl;
            } else {
                cout << c << " ";
                cout << b << " " << a << endl;
            }
        } else {
            if (a < c) {
                cout << a << " ";
                if (c < b) cout << c << " " << b << endl;
                else cout << b << " " << c << endl;
            } else {
                cout << c << " ";
                cout << a << " " << b << endl;
            }
        }
    }

    return 0;
}