/**
 * 虽然草儿是个路痴（就是在杭电待了一年多，居然还会在校园里迷路的人，汗~),但是草儿仍然很喜欢旅行，
 * 因为在旅途中 会遇见很多人（白马王子，^0^），很多事，还能丰富自己的阅历，还可以看美丽的风景……草儿想去很多地方，
 * 她想要去东京铁塔看夜景，去威尼斯看电影，去阳明山上看海芋，去纽约纯粹看雪景，去巴黎喝咖啡写信，去北京探望孟姜女……眼看寒假就快到了，
 * 这么一大段时间，可不能浪费啊，一定要给自己好好的放个假，可是也不能荒废了训练啊，所以草儿决定在要在最短的时间去一个自己想去的地方！
 * 因为草儿的家在一个小镇上，没有火车经过，所以她只能去邻近的城市坐火车（好可怜啊~）。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
struct link {
    int destination;
    int time;
};
struct address {
    int location;
    vector<struct link> link;
};

int main() {
    int t, s, d;
    while (cin >> t >> s >> d) {
        vector<struct address> graph;
        /**初始化出发点*/
        struct address initial;
        initial.location = 0;
        graph.push_back(initial);
        /**是否已有记录标记*/
        map<int, bool> enter;
        enter[initial.location] = true;
        /**记录实际位置在图结构中的索引*/
        map<int, int> realIndex;
        realIndex[initial.location] = 0;

        int index = 1;
        for (int i = 0; i < t; ++i) {
            int start, end, time;
            cin >> start >> end >> time;
            if (!enter[start]) {
                struct address tmp;
                tmp.location = start;
                enter[tmp.location] = true;
                realIndex[tmp.location] = index;
                ++index;
                graph.push_back(tmp);
            }

            if (!enter[end]) {
                struct address tmp;
                tmp.location = end;
                enter[tmp.location] = true;
                realIndex[tmp.location] = index;
                ++index;
                graph.push_back(tmp);
            }

            struct link tmpLink1, tmpLink2;
            tmpLink1.destination = end;
            tmpLink1.time = time;
            graph[realIndex[start]].link.push_back(tmpLink1);
            tmpLink2.destination = start;
            tmpLink2.time = time;
            graph[realIndex[end]].link.push_back(tmpLink2);
        }

        for (int i = 0; i < s; ++i) {
            int love;
            cin >> love;
            if (!enter[love]) {
                struct address tmp;
                tmp.location = love;
                enter[tmp.location] = true;
                realIndex[tmp.location] = index;
                ++index;
                graph.push_back(tmp);
            }
            struct link tmpLink1, tmpLink2;
            tmpLink1.destination = love;
            tmpLink1.time = 0;
            graph[realIndex[initial.location]].link.push_back(tmpLink1);
            tmpLink2.destination = initial.location;
            tmpLink2.time = 0;
            graph[realIndex[love]].link.push_back(tmpLink2);
        }

        vector<int> favourites;
        for (int i = 0; i < d; ++i) {
            int tmpValue;
            cin >> tmpValue;
            if (!enter[tmpValue]) {
                struct address tmp;
                tmp.location = tmpValue;
                enter[tmp.location] = true;
                realIndex[tmp.location] = index;
                ++index;
                graph.push_back(tmp);
            }
            favourites.push_back(tmpValue);
        }


        int count = graph.size();
        vector<int> minPath(graph.size(), INT_MAX);
        vector<bool> visited(graph.size(), false);
        minPath[realIndex[initial.location]] = 0;
        while (count--) {
            /* long long tmpMin = INT_MAX, startIndex = 0;
             while (startIndex < visited.size() && visited[startIndex]) ++startIndex;
             if (startIndex == minPath.size()) break;
             for (int i = 0; i < minPath.size(); ++i) {
                 if (!visited[i]) {
                     if (tmpMin > minPath[i]) {
                         startIndex = i;
                         tmpMin = minPath[i];
                     }
                 }
             }*/
            int startIndex = -1;
            int tmpMin = INT_MAX;
            for (int i = 0; i < minPath.size(); ++i) {
                if (!visited[i] && tmpMin >= minPath[i]) {
                    startIndex = i;
                    tmpMin = minPath[i];
                }
            }
            if (startIndex == -1) break;
            visited[startIndex] = true;
            vector<struct link> links = graph[startIndex].link;
            long long cost = minPath[startIndex];
            for (int i = 0; i < links.size(); ++i) {
                int location = links[i].destination, time = links[i].time;
                if (!visited[realIndex[location]]) {
                    int tmpCost = cost + time;
                    if (tmpCost < minPath[realIndex[location]]) minPath[realIndex[location]] = tmpCost;
                }
            }


        }


        int realMin = minPath[realIndex[favourites[0]]];
        for (int i = 1; i < favourites.size(); ++i) {
            if (realMin > minPath[realIndex[favourites[i]]]) realMin = minPath[realIndex[favourites[i]]];
        }


        cout << realMin << endl;
    }
    return 0;
}
/**
 * 迪杰斯特拉算法求最短路径的应用。
 * 注意在重边的情况下，若用矩阵存储，会费点事，用邻接表直接无视
 * 此题所用vector容器加结构体加map可作为生成邻接表的模板。
 * 迪杰斯特拉算法的迭代过程，有个奇葩的东西，每次循环选取最小未被访问的点时
 * 注释中代码竟然判错，注释代码思路其实很简单，相当于打擂台，先一次遍历选取一个未被访问的点，保存，当成最小的点
 * 然后再遍历一次，打擂台，寻找真正最小的点，但判错，究其原因，在于INT_MAX，INT_MAX意义在于表示迭代过程中暂未达到的点与实际意义上
 * 与起点不联通的点。
 * 但用如上两次遍历方式，第一次遍历时他很有可能被选上(他其实从迭代开始到结束都不应该选上)，
 * 它一旦选上，第二次遍历的时候，恰恰剩余的点都为无法到达的点，那么他就无法被更改(只是起点到这些点无法到达，但不代表起点无法到达的点不是联通的)
 * 那么他会开始迭代(可能会跟其他无法到达的点联通)，因为是int型最大INT_MAX，再加就成负数了，那么下次迭代这个本无法到达的点就
 * 直接选上，就错的认不得家(可以开long long型解决，注释部分)，这个问题等价于如上未注释部分(tmpMin > minPath[i] > 变为 >=)
 * 所以ac的一次遍历，一定要是> 而非>= 或者开long long 直接无视这个bug
 * */