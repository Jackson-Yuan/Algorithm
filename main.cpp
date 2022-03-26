#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include "set"
#include "stack"
#include "algorithm"

using namespace std;

int find(int start, vector<int> &root) {
    int tmp = start;
    int res;
    while (root[tmp] != -1) tmp = root[tmp];
    res = tmp;

    while (root[start] != -1) {
        tmp = root[start];
        root[start] = res;
        start = tmp;
    }

    return res;
}

struct node {
    int index;
    int val;

    bool operator<(const node &b) const {
        if (val == b.val) return index < b.index;
        else return val < b.val;
    }

    node(int index, int val) {
        this->index = index;
        this->val = val;
    }
};

class Solution {
public:
    int maxCoins(vector<int> &nums) {

        set<node> s;
        for (int i = 0; i < nums.size(); ++i) {
            node cur(i, nums[i]);
            s.insert(cur);
        }

        int ans = 0;


        while (!s.empty()) {
            auto ite = s.begin();
            node cur = *ite;
            s.erase(ite);


            int leftIndex = -1, rightIndex = nums.size();
            int leftVal = 1, rightVal = 1;
            ite = s.begin();
            while (ite != s.end()) {
                if (ite->index < cur.index) {
                    if (cur.index - ite->index < cur.index - leftIndex) {
                        leftIndex = ite->index;
                        leftVal = ite->val;
                    }
                } else {
                    if (ite->index - cur.index < rightIndex - cur.index) {
                        rightIndex = ite->index;
                        rightVal = ite->val;
                    }
                }

                ++ite;
            }


            ans += leftVal * cur.val * rightVal;
        }


        return ans;

    }
};
int main() {
    int i = 1;

    cout << ();


}

