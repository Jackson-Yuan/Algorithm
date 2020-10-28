/**
 * 作为球迷，一定想看尽量多的完整的比赛，当然，作为新时代的好青年，你一定还会看一些其它的节目，比如新闻联播（永远不要忘记关心国家大事）
 * 、非常6+7、超级女生，以及王小丫的《开心辞典》等等，假设你已经知道了所有你喜欢看的电视节目的转播时间表，
 *  你会合理安排吗？（目标是能看尽量多的完整节目）
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct channel {
    int start;
    int end;
};

bool cmp(struct channel a, struct channel b) {
    return a.end < b.end;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<struct channel> channels;
        for (int i = 0; i < n; ++i) {
            struct channel tmp;
            cin >> tmp.start >> tmp.end;
            channels.push_back(tmp);
        }

        sort(channels.begin(), channels.end(), cmp);

        int last = channels[0].end;
        int count = 1;

        for (int i = 1; i < channels.size(); ++i) {
            if (channels[i].start >= last) {
                ++count;
                last = channels[i].end;
            }
        }

        cout << count << endl;
    }

    return 0;
}