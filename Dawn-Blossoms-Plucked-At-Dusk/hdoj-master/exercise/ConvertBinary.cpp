/**
 * Give you a number on base ten,you should output it on base two.(0 < n < 1000)
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string str;
        while (n) {
            int tmp = n % 2;
            str.append(1, '0' + tmp);
            n /= 2;
        }

        reverse(str.begin(), str.end());
        cout << str << endl;
    }

    return 0;
}