#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;


/**
 *
 * 数学原理题 若干个数 排列成最小的数
 *
 * 原理为利用如下排序规则
 * 任意的x，y  若xy < yx(xy变现为拼接的数)，则x < y
 *
 * 按照此从小到大排序 直接拼接就是结果
 * */
bool cmp(string &a, string &b) {
    string a_head = a + b;
    string b_head = b + a;
    return a_head < b_head;
}

class Solution {
public:
    string minNumber(vector<int> &nums) {
        vector<string> nums_str;
        for (int cur : nums) {
            nums_str.push_back(to_string(cur));
        }

        sort(nums_str.begin(), nums_str.end(), cmp);

        string ans;

        for (string cur : nums_str) {
            ans += cur;
        }

        return ans;
    }
};

int main() {
    string a = "1";
    string b = "2";

    cout << (a < b);
}