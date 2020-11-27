/**
 * 给定四个包含整数的数组列表A , B , C , D ,计算有多少个元组 (i, j, k, l)，使得A[i] + B[j] + C[k] + D[l] = 0。
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度N，且 0 ≤ N ≤ 500 。
 * 所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过2^31 - 1 。
 * */
#include "iostream"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                int val = A[i] + B[j];
                ++m[val];
            }
        }

        int ans = 0;
        for (int i = 0; i < C.size(); ++i) {
            for (int j = 0; j < D.size(); ++j) {
                int val = -(C[i] + D[j]);
                ans += m[val];
            }
        }

        return ans;
    }
};
/**
 * 此题如果暴力，复杂度暴增n^4，不妨先分组
 * 将4个数组两两分组，头两个先遍历所有组合，用hash保存出现次数
 * 后两个遍历所有组合，取相反数，看hash中对应个数，相加即可。
 * 这样答案也有，复杂度也降了。
 * */