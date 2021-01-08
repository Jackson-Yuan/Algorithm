#include "iostream"
#include "vector"

using namespace std;

int findMid(vector<int> &array, int left, int right);

void quickSort(vector<int> &array, int left, int right) {
    if (left < right) {
        int divide = findMid(array, left, right);
        quickSort(array, divide + 1, right);
        quickSort(array, left, divide - 1);
    }
}


int findMid(vector<int> &array, int left, int right) {
    int compare = array[left];
    while (left < right) {
        while (left < right && array[right] <= compare) --right;
        array[left] = array[right];
        while (left < right && array[left] >= compare) ++left;
        array[right] = array[left];
    }

    array[left] = compare;
    return left;
}


int main() {
    vector<int> array = {1, 4, 5, 5, 2, 6};
    quickSort(array, 0, array.size() - 1);
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}