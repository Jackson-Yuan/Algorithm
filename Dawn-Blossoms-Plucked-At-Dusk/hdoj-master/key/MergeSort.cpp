/**
 * 归并排序
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

void mergeSort(vector<int> &nums, int left, int right);

void sort(vector<int> &nums, int left, int right) {
    if (left == right) return;;
    int mid = left + (right - left) / 2;
    sort(nums, left, mid);
    sort(nums, mid + 1, right);
    mergeSort(nums, left, right);
}

void mergeSort(vector<int> &nums, int left, int right) {
    vector<int> tmp;
    for (int i = left; i <= right; ++i) {
        tmp.push_back(nums[i]);
    }
    int mid = (tmp.size() - 1) / 2;/**对应好left相当于0 right相当于tmp.size - 1，因为在分组时，中点是这样定的，划分是依据中点划分*/
    int i = 0, j = mid + 1;
    for (int k = left; k <= right; ++k) {
        if (i == mid + 1) {
            nums[k] = tmp[j];
            ++j;
        } else if (j == tmp.size()) {
            nums[k] = tmp[i];
            ++i;
        } else if (tmp[i] > tmp[j]) {/**稳定排序的关键所在，>= 就不稳定*/
            nums[k] = tmp[j];
            ++j;
        } else {
            nums[k] = tmp[i];
            ++i;
        }
    }
}

int main() {
    vector<int> array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(array, 0, array.size() - 1);
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
}