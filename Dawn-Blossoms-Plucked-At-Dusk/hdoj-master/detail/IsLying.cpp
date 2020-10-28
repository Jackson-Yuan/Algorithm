/**
 * 一个活动有N个人参加，
 * 一个主持人和N-1个普通参加者，其中所有的人都认识主持人，主持人也认识所有的人，主持人要求N-1个参加者说出他们在参加者中所认识的人数，
 * 如果A认识B，则B认识A，所以最少是会认识一个人，就是主持人，他们说出了自己所认识的人数后，需要判断他们中有没有人说谎。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> res(n - 1, -1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> res[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            sort(res.begin(), res.end(), cmp);
            if (res[n - 2] == 0) {
                cout << "lie" << endl;
                break;
            } else if (res[i] == 1) {
                cout << "maybe truth" << endl;
                break;
            } else {
                for (int j = 1; j < res[i]; ++j) {
                    --res[i + j];
                }
            }
        }
    }

    return 0;
}

/**
 * 根据题意，我们把这个想成一幅图，每个人都是一个点，最开始每个点都和中心点（主持人有连线），
 * 接下来，每个人都开始说，自己有几根连线（也就是自己认识多少人），我们把所有人（除主持人）的连线都切除，
 * 那么如果没有人撒谎的话，最后应该每个人都只有一条连接主持人的线。同时，我们并不知道谁连着谁，所以我们在切线的时候，优先斩断线多的点。
 * */