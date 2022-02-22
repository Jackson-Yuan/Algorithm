#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int greedy(vector<int> x, int n) {
    int sum = 0, k = x.size();
    for (int i = 0; i < k; ++i) {
        if (x[i] > n) {
            cout << "No";
            return -1;
        }
        for (int j = 0, s = 0; j < k; ++j) {
            s += x[j];
            if (s > n) {
                ++sum;
                s = x[j];
            }
        }
    }

    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(k + 1);
    for (int i = 0; i < x.size(); ++i) {
        cin >> x[i];
    }
    cout << greedy(x, n);
}