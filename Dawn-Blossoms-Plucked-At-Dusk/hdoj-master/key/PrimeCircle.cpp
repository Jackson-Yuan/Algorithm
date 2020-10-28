/**
 * 素数环问题，1~n的整数，绕成环，相邻两个的和为素数
 * 按字典序打印
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int n;

vector<int> list;
vector<bool> visited;

bool isPrime(int val) {
    for (int i = 2; i <= sqrt(val); ++i) {
        if (val % i == 0) return false;
    }

    return true;
}

void dfs(int index) {
    if (index == n) {
        if (isPrime(list[0] + list[list.size() - 1])) {
            for (int i = 0; i < list.size(); ++i) {
                cout << list[i];
            }

            cout << endl;
        }

        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && isPrime(list[index - 1] + i)) {
            list.push_back(i);
            visited[i] = true;
            dfs(index + 1);
            visited[i] = false;
            list.pop_back();
        }
    }

}

int main() {
    while (cin >> n) {
        visited = vector<bool>(n + 1, false);
        list.clear();
        list.push_back(1);
        visited[1] = true;
        dfs(1);
    }
}