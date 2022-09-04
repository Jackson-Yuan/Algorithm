#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "stack"

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<char> str(n);
    for (int i = 0; i < n; ++i) cin >> str[i];


    vector<int> right(str.size(), 0);

    if (str[str.size() - 1] == ')') right[str.size() - 1] = 1;

    for (int i = str.size() - 2; i >= 0; --i) {
        if (str[i] == ')') right[i] = right[i + 1] + 1;
        else right[i] = right[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            if (right[i] >= k) ans += right[i] - k + 1;
        }
    }

    cout << ans << endl;
    return 0;


}
