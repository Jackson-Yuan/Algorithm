#include "iostream"
#include "vector"

using namespace std;

/**
 * 寻找数组最小的k个数
 * 利用快排分割函数的作用（指定数左边都比它小，右边都比它大），若分割数的插入位置为k-1，则最小的k个数显而易见
 * */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> ans;
        if (arr.size() == 0 || k == 0) return ans;
        int split_index = split(arr, 0, arr.size() - 1);

        int start = 0, end = arr.size() - 1;
        while (split_index != k - 1) {
            if (split_index > k - 1) {
                end = split_index - 1;
                split_index = split(arr, start, end);
            } else {
                start = split_index + 1;
                split_index = split(arr, start, end);
            }
        }

        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i]);
        }

        return ans;
    }

    int split(vector<int> &num, int start, int end) {
        int compare = num[start];

        while (start < end) {
            while (start < end && num[end] >= compare) --end;
            num[start] = num[end];
            while (start < end && num[start] <= compare) ++start;
            num[end] = num[start];
        }

        num[start] = compare;
        return start;
    }
};

