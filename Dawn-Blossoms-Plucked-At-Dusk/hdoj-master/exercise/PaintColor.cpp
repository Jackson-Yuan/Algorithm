/**
 * 有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

/*
long long countValue;
int n;
vector<int> color;
void dfs(int index, int pre){
    if (index == n){
        if (color[0] != color[color.size() - 1] || color.size() == 1){
            ++countValue;
        }
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (i != pre){
            color.push_back(i);
            dfs(index + 1, i);
            color.pop_back();
        }
    }
}

int main(){
    while (cin >> n){
        countValue = 0;
        color.clear();
        dfs(0, -1);
        cout << countValue << endl;
    }

    return 0;
}*/

int main() {
    int n;
    while (cin >> n) {
        vector<long long> res;
        res.push_back(3);
        res.push_back(6);
        res.push_back(6);
        res.push_back(18);

        for (int i = 4; i < n; ++i) {
            long long tmp = res[i - 1] + 2 * res[i - 2];
            res.push_back(tmp);
        }

        cout << res[n - 1] << endl;
    }
    return 0;
}
