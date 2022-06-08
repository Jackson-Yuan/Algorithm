#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/**
 * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
 * 请你重新构造并返回输入数组people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
 * 链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
 * */

/**
 * 本题的思路是通过排序进行贪心
 * 排序的规则是按照身高从小到大，若身高一样，则按照大于等与自身身高的人数，从大到小
 *
 * 开一个待插入数组 然后遍历排序后的数组，每遍历一个元素，根据身高比大于等于自身的人数按顺序寻找待插入
 * 数组中还未放置元素的位置
 *
 * 因为之前排序规则的缘故，可以保证重建关系符合要求
 * */
bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) return a[1] > b[1];
    else return a[0] < b[0];
}


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(people.size());
        for (vector<int> &cur: people) {
            int spaces = cur[1] + 1;

            for (int i = 0; i < ans.size(); ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (spaces == 0) {
                        ans[i] = cur;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
