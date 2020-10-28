/**
 * 有一群人，打乒乓球比赛，两两捉对撕杀，每两个人之间最多打一场比赛。
 * 球赛的规则如下：
 * 如果A打败了B，B又打败了C，而A与C之间没有进行过比赛，那么就认定，A一定能打败C。
 * 如果A打败了B，B又打败了C，而且，C又打败了A，那么A、B、C三者都不可能成为冠军。
 * 根据这个规则，无需循环较量，或许就能确定冠军。你的任务就是面对一群比赛选手，在经过了若干场撕杀之后，确定是否已经实际上产生了冠军。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct link {
    int winner;
    int loser;
};

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        map<string, int> realIndex;
        int index = 1;
        vector<struct link> links;
        for (int i = 0; i < n; ++i) {
            struct link current;
            string winner, loser;
            cin >> winner >> loser;
            if (realIndex[winner] == 0) {
                realIndex[winner] = index;
                ++index;
            }

            if (realIndex[loser] == 0) {
                realIndex[loser] = index;
                ++index;
            }

            current.winner = realIndex[winner];
            current.loser = realIndex[loser];
            links.push_back(current);
        }

        vector<int> unit(index, 0);
        for (int i = 0; i < links.size(); ++i) {
            int loser = links[i].loser;
            ++unit[loser];
        }
        int count = 0;
        for (int i = 1; i < unit.size(); ++i) {
            if (unit[i] == 0) ++count;
        }

        if (count == 1) cout << "Yes";
        else cout << "No";

        cout << endl;
    }

    return 0;
}
/**
 * 此题转换一下就是看没被锤的人是否有且只有一个
 *
 * 当然可以利用拓补排序也可以
 * */