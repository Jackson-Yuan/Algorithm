/**
 * we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
 * Give you a letter x and a number y , you should output the result of y+f(x).
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
    cin >> n;
    while (n--) {
        getchar();
        char a;
        int b, aa;
        cin >> a >> b;
        if (a >= 'a' && a <= 'z') {
            aa = a - 'a' + 1;
            aa = -aa;
        }
        if (a >= 'A' && a <= 'Z') {
            aa = a - 'A' + 1;
        }

        cout << (aa + b) << endl;
    }

    return 0;
}