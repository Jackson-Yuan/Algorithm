#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<int> list;
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        list = candidates;
        sort(list.begin(), list.end());
        dfs(0, target);
        return res;
    }

    int getSum(vector<int> path) {
        int sum = 0;
        for (int i = 0; i < path.size(); ++i) {
            sum += path[i];
        }

        return sum;
    }

    void dfs(int start, int target) {
        if (getSum(path) == target) {
            res.push_back(path);
            return;
        }
        if (start == list.size() || getSum(path) > target) return;

        for (int i = start; i < list.size(); ++i) {
            if (list[i] > target) return;
            if (i > start && list[i] == list[i - 1]) continue;
            path.push_back(list[i]);
            dfs(i + 1, target);
            path.pop_back();
        }
    }
};
/**
 * 没啥说头，dfs暴力搜索秒杀之，暴力搜索start参数避免往回搜造成重复，唯一注意的一段代码
 *  if(i > start && list[i] == list[i - 1]) continue;去除重复的组合如[1,2,1] target为3 没有这段代码会出现[1,2],[1,2]
 *  当然也可以用hash来判断重复
 * */