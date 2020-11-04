/**
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto &interval: intervals) {
            if (interval[0] > right) {
                /**
                 * 在插入区间的右侧且无交集
                 * */
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left) {
                /**
                 * 在插入区间的左侧且无交集
                 * */
                ans.push_back(interval);
            } else {
                /**
                 * 与插入区间有交集，计算它们的并集
                 * */
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
/**
 * 思路就是先模拟插入过程，起先是想把新区间直接插入进新数组，这样搞情况爆炸多
 * 正确的方式应该是加一个判断一个
 * 具体判断情况如代码所示，精髓在于动态地扩充这个区间
 * */