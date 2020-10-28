#include<iostream>
#include<algorithm>

using namespace std;
int dp[1000];
int a[1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int maxValue = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > maxValue) maxValue = dp[i];
    }
    cout << maxValue << endl;
}
