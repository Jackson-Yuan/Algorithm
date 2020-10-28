/**
 * 输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
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
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<int> array;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            array.push_back(tmp);
        }

        int min = array[0];
        int minIndex = 0;
        for (int j = 1; j < array.size(); ++j) {
            if (array[j] < min) {
                min = array[j];
                minIndex = j;
            }
        }

        int tmp = array[minIndex];
        array[minIndex] = array[0];
        array[0] = tmp;

        for (int k = 0; k < array.size(); ++k) {
            cout << array[k];
            if (k != array.size() - 1) cout << " ";
        }

        cout << endl;
    }

    return 0;
}