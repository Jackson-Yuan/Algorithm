#include "iostream"
#include "vector"

using namespace std;
int i, j;

int divideSort(vector<int> array, int target) {
    int left = 0, right = array.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > target) {
            right = mid - 1;
            j = mid;
        } else if (array[mid] < target) {
            left = mid + 1;
            i = mid;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> array = {1, 2, 3, 5, 6};
    int ans = divideSort(array, 0);

    if (ans == -1) {
        cout << i << ";" << j << endl;
    } else cout << ans << endl;
}