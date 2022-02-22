#include "iostream"
#include "vector"

using namespace std;


/**
 * 找出第n大的丑数
 * 可以逐个暴力尝试判断丑数
 * 但极其耗时，不妨这样想，大的丑数都是由小的丑数*2、*3、*5得来
 * 我们只需将小的丑数预选保存下来，通过*2 *3 *5 逐个排序，直到指定的n个
 * 这种想法与素数筛法类似
 * */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n, 0);
        ans[0] = 1;
        int next = 1;
        int point2 = 0, point3 = 0, point5 = 0;

        while (next < n) {
            int val = min(min(ans[point2] * 2, ans[point3] * 3), ans[point5] * 5);
            ans[next] = val;

            while (2 * ans[point2] <= ans[next]) ++point2;
            while (3 * ans[point3] <= ans[next]) ++point3;
            while (5 * ans[point5] <= ans[next]) ++point5;

            ++next;
        }

        return ans[n - 1];
    }
};

