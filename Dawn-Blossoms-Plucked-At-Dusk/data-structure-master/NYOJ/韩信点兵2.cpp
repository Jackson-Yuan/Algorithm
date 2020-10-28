#include<iostream>

using namespace std;

int main() {
    int a, b, c, n;
    cin >> a >> b >> c;
    n = (70 * a + 21 * b + 15 * c) % 105;
    if (n >= 10 && n <= 100) cout << n << endl;
    else cout << "No answer";
} 
