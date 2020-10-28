#include<iostream>
#include<string.h>

using namespace std;
int allocated[1500][1500];
bool bound[1500][1500];
int num[1500];
int minValue, n;

void dfs(int id, int sum) {
    if (sum >= minValue) return;
    if (id > n) {
        if (sum < minValue) minValue = sum;
        return;
    }

    /**如果可以 分配已有的考场*/
    for (int i = 1; i <= sum; i++) {
        int token = 1;
        for (int j = 0; j < num[i]; j++) {
            if (bound[id][allocated[i][j]] == 1) {
                token = 0;
                break;
            }
        }
        if (token) {
            allocated[i][num[i]] = id;
            num[i]++;
            dfs(id + 1, sum);
            num[i]--;
        }
    }

    /**开辟新考场*/
    allocated[sum + 1][num[sum + 1]] = id;
    num[sum + 1]++;
    dfs(id + 1, sum + 1);
    num[sum + 1]--;
}

int main() {
    cin >> n;
    int k;
    cin >> k;
    memset(allocated, 0, sizeof(allocated));
    memset(bound, 0, sizeof(bound));
    memset(num, 0, sizeof(num));

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        bound[a][b] = 1;
        bound[b][a] = 1;
    }

    minValue = 0x3f3f3f3f;
    dfs(1, 0);


    cout << minValue << endl;
}
