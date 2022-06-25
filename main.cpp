#include <iostream>
#include <cassert>
#include <string>
#include "map"
#include "unordered_map"
#include "stack"
#include "vector"

using namespace std;
struct point {
    int start;

    int end;
};

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, bool> flag;
        unordered_map<char, int> mapp;
        for (char cur: t) {
            flag[cur] = true;
        }

        int minDistance = INT_MAX;
        string resStr = "";


        for (int i = 0; i < s.length(); ++i) {
            char cur = s[i];
            if (flag.find(cur) != flag.end()) {
                mapp[cur] = i;
            }

            point res = getDistance(mapp, flag);
            if (res.start != -1 && res.end != -1) {
                if (res.end - res.start + 1 < minDistance) {
                    minDistance = res.end - res.start + 1;
                    resStr = s.substr(res.start, res.end - res.start + 1);
                }

            }
        }

        return resStr;
    }


    point getDistance(unordered_map<char, int> &mapp, unordered_map<char, bool> &flag) {

        auto ite = flag.begin();
        int maxIndex = INT_MIN;
        int minIndex = INT_MAX;

        point res;
        while (ite != flag.end()) {
            auto ite_index = mapp.find(ite->first);
            if (ite_index == mapp.end()) {
                res.start = -1;
                res.end = -1;
                return res;
            }
            if (ite_index->second > maxIndex) {
                maxIndex = ite_index->second;
            }

            if (ite_index->second < minIndex) {
                minIndex = ite_index->second;
            }
            ++ite;
        }

        res.start = minIndex;
        res.end = maxIndex;


        return res;
    }
};



int main() {
    string a = "abc";

    cout << (a.substr(0, 0) == "");

}

