/**
 * There are many lamps in a line. All of them are off at first. A series of operations are carried out on these lamps. On the i-th operation,
 * the lamps whose numbers are the multiple of i change the condition ( on to off and off to on ).
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
        int start = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                if (start == 0) start = 1;
                else start = 0;
            }
        }

        cout << start << endl;
    }
    return 0;
}