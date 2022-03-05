#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include "set"
#include "stack"

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (end - start) / 2 + start;

            int count = countRange(nums, start, mid);

            if (start == end) {
                if (count > 1) return start;
                else break;
            }

            if (count > mid - start + 1) end = mid;
            else start = mid + 1;
        }

        return -1;
    }

    int countRange(vector<int> &nums, int start, int end) {
        int count = 0;

        for (int val : nums) {
            if (val >= start && val <= end) ++count;
        }

        return count;
    }
};

int countRange(vector<int> &nums, int start, int end);

int getDuplication(vector<int> num) {
    int start = 0;
    int end = num.size() - 1;

    while (start <= end) {
        int mid = (end - start) / 2 + start;
        int count = countRange(num, start, mid);

        if (end == start) {
            if (count > 1) return start;
            else break;
        }

        if (count > mid - start + 1) end = mid;
        else start = mid + 1;
    }

    return -1;
}

int countRange(vector<int> &nums, int start, int end) {
    int count = 0;
    for (int val : nums) {
        if (val >= start && val <= end) {
            ++count;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    if
}