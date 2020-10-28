#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }
};
/**
 * 此题难于解决的要求就在，一个数可以无限被选，和不能出现重复组合
 * 无限被选与不能出现重复组合：靠dfs函数start参数完美解决
 * 再结束递归的条件上，没有比较暴力所得的总和是否为target而是暴力过程中，不断减小值
 * 看是否为0，很巧妙
 * */