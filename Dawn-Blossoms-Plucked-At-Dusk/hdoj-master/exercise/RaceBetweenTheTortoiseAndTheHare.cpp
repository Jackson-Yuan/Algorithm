/**
 * 据说在很久很久以前，可怜的兔子经历了人生中最大的打击——赛跑输给乌龟后，心中郁闷，发誓要报仇雪恨，
 * 于是躲进了杭州下沙某农业园卧薪尝胆潜心修炼，终于练成了绝技，能够毫不休息得以恒定的速度(VR m/s)一直跑。兔子一直想找机会好好得教训一下乌龟，以雪前耻。
 * 最近正值HDU举办50周年校庆，社会各大名流齐聚下沙，兔子也趁此机会向乌龟发起挑战。虽然乌龟深知获胜希望不大，不过迫于舆论压力，只能接受挑战。
 * 比赛是设在一条笔直的道路上，长度为L米，规则很简单，谁先到达终点谁就算获胜。
 * 无奈乌龟自从上次获胜以后，成了名龟，被一些八卦杂志称为“动物界的刘翔”，广告不断，手头也有了不少积蓄。
 * 为了能够再赢兔子，乌龟不惜花下血本买了最先进的武器——“"小飞鸽"牌电动车。这辆车在有电的情况下能够以VT1 m/s的速度“飞驰”，
 * 可惜电池容量有限，每次充满电最多只能行驶C米的距离，以后就只能用脚来蹬了，乌龟用脚蹬时的速度为VT2 m/s。
 * 更过分的是，乌龟竟然在跑道上修建了很多很多（N个)的供电站，供自己给电动车充电。其中，每次充电需要花费T秒钟的时间。
 * 当然，乌龟经过一个充电站的时候可以选择去或不去充电。
 * 比赛马上开始了，兔子和带着充满电的电动车的乌龟并列站在起跑线上。你的任务就是写个程序，判断乌龟用最佳的方案进军时，能不能赢了一直以恒定速度奔跑的兔子。
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

double min(double a, double b) {
    return a < b ? a : b;
}

int main() {
    int len;
    int n, digitalLen, digitalTime;
    int speedR, speedT1, speedT2;
    while (cin >> len >> n >> digitalLen >> digitalTime >> speedR >> speedT1 >> speedT2) {
        vector<int> distance(n + 2, 0);
        distance[n + 1] = len;
        vector<double> dp(n + 2, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> distance[i];
        }

        for (int i = 1; i <= n + 1; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                /**虽说把起点当做充电站，但依据题意，是充电且不耗时间*/
                if (j == 0) {
                    int diff = distance[i] - distance[j];
                    if (digitalLen >= diff) {
                        dp[i] = min(dp[i], dp[j] + (double) diff / speedT1);
                    } else {
                        double compare = dp[j] + (double) digitalLen / speedT1;
                        compare += (double) (diff - digitalLen) / speedT2;
                        dp[i] = min(dp[i], compare);
                    }
                } else {
                    int diff = distance[i] - distance[j];
                    double x = digitalTime; /**charge power*/
                    /**double y = 0; 关于y的计算逻辑上是说不通的，虽然带上y也算对
                    y += (double) diff / speedT2;*/
                    if (digitalLen >= diff) {
                        x += (double) diff / speedT1;
                    } else {
                        x += (double) digitalLen / speedT1;
                        x += (double) (diff - digitalLen) / speedT2;
                    }

                    dp[i] = min(dp[i], dp[j] + x);
                    /**dp[i] = min(dp[i], dp[j] + y);*/
                }
            }
        }

        double targetTime = (double) len / speedR;
        if (dp[n + 1] < targetTime) {
            cout << "What a pity rabbit!" << endl;
        } else {
            cout << "Good job,rabbit!" << endl;
        }
    }

    return 0;
}
/**
 * 这道题好好理解一波
 * 要点主要是在每个充电站是否选择充电
 * 这个决策有两种，暴力或者dp
 * 显然此题暴力应该没得玩
 * 用dp
 * dp[i]数组的意义为到达第i个充电站所需的最短时间
 * 为了方便，起点当成一个特殊的充电站（必定充电且不耗费充电时间），终点也当成一个特殊的充电站（压根不要有操作）
 * 至于状态转移方程，这地方就有点巧妙
 * 例如求dp[i]，遍历i之前所有的充电站到此充电站的最短时间，为何要这样遍历？
 * 因为有这么几种情况，可能起点到终点的距离一次充电正好够，如果途中在充电浪费时间
 * 或者充一次电后，哪怕经过一个充电站，可能剩余的电量加脚蹬更为划算，所以dp的递推直接是由i之前每个充电站到达的最小时间
 * 加上在这个充电站充满电后到达i充电站所需的时间，这些值取最小值即可
 * */