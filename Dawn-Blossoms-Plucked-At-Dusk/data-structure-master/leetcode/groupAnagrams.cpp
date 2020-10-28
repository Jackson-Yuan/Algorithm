#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    vector<vector<int>> list;
    vector<vector<string>> res;
    map<string, int> m;
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int index = 1;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m[tmp] == 0) {
                m[tmp] = index;
                ++index;
                vector<int> path;
                path.push_back(i);
                list.push_back(path);
            } else {
                list[m[tmp] - 1].push_back(i);
            }
        }

        for (int i = 0; i < list.size(); ++i) {
            vector<string> path;
            for (int j = 0; j < list[i].size(); ++j) {
                path.push_back(strs[list[i][j]]);
            }
            res.push_back(path);
        }


        return res;
    }
};
/**
 *利用排序加hash先行分组，储存索引
 * 然后依次遍历即可
 * */