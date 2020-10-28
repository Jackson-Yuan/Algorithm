/**
 * 如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。
 * 给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：
 * s 是一个尽可能长的快乐字符串。
 * s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
 * s 中只含有 'a'、'b' 、'c' 三种字母。
 * 如果不存在这样的字符串 s ，请返回一个空字符串 ""。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct point {
    char val;
    int count;
};

bool cmp(point a, point b) {
    return a.count > b.count;
}

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<point> points;
        point pa, pb, pc;
        pa.val = 'a';
        pa.count = a;
        points.push_back(pa);
        pb.val = 'b';
        pb.count = b;
        points.push_back(pb);
        pc.val = 'c';
        pc.count = c;
        points.push_back(pc);
        string res;

        char pre = 'd';
        while (true) {
            sort(points.begin(), points.end(), cmp);
            if (points[0].count == 0) break;

            int start = 0;
            int limit = 2;
            if (pre != 'd' && points[start].val == pre) --limit;/**若新一轮最大的字符与前面摆放的用来分割的那个一致，则这次最大的字符只摆放一个，并非选择次多的*/

            if (points[start].count >= limit) {
                res.append(limit, points[start].val);
                points[start].count -= limit;
            } else if (points[start].count != 0) {
                res.append(points[start].count, points[start].val);
                points[start].count = 0;
            }

            int next = -1;
            for (int i = 0; i < points.size(); ++i) {
                if (i != start && points[i].count != 0) {
                    if (next == -1) next = i;
                    else if (points[i].count < points[next].count) next = i;/**选取个数最小的用来分割，当然也可以随便选一个不为0的也可*/
                }
            }
            if (next == -1) break;

            pre = points[next].val;

            res.append(1, points[next].val);
            points[next].count -= 1;

        }

        return res;

    }

};
/**
 * 算法其实就是贪心的思路，你要问为什么，其实也说不出来
 * 但大概思路是可以理解的，优先放个数最多的字符，再用个数最小的来分割
 * 至于代码中注释部分为什么这么做，第一处是按照样例改出来的
 * 第二处两种方法试过，都对，也就这样了
 * */