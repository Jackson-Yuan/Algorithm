/**
 * 算法笔记 p211
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

#define END 200001
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> notPrime(END, false);
    int count = 0;
    int index = 0;
    for (int i = 2; i < END; ++i) {
        if (notPrime[i]) continue;
        ++count;
        if (count >= n && count <= m) {
            if (index != 0 && index % 10 == 0) cout << endl;
            if (index % 10 != 0) cout << " ";
            cout << i;
            ++index;
        }
        for (long long j = (long long) i * i; j < END; j += i) {
            notPrime[j] = true;
        }
    }
    return 0;
}