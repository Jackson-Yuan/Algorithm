/**问题描述
　　小明喜欢在一个围棋网站上找别人在线对弈。这个网站上所有注册用户都有一个积分，代表他的围棋水平。


　　小明发现网站的自动对局系统在匹配对手时，只会将积分差恰好是K的两名用户匹配在一起。如果两人分差小于或大于K，系统都不会将他们匹配。


　　现在小明知道这个网站总共有N名用户，以及他们的积分分别是A1, A2, ... AN。


　　小明想了解最多可能有多少名用户同时在线寻找对手，但是系统却一场对局都匹配不起来(任意两名用户积分差不等于K)？
输入格式
　　第一行包含两个个整数N和K。
　　第二行包含N个整数A1, A2, ... AN。


　　对于30%的数据，1 <= N <= 10
　　对于100%的数据，1 <= N <= 100000, 0 <= Ai <= 100000, 0 <= K <= 100000
输出格式
　　一个整数，代表答案。
样例输入
10 0
1 4 2 8 5 7 1 4 2 8
样例输出
6*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;
int a[100001];
int result[100001];
int dp[100001];

int main() {
    int n, k;
    while (cin >> n >> k) {
        memset(a, 0, sizeof(a));
        int maxValue = -1;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a[temp]++;
            if (temp > maxValue) maxValue = temp;
        }

        int count = 0;
        if (k == 0) {
            for (int i = 0; i <= maxValue; i++) {
                if (a[i] != 0) count++;
            }
            cout << count << endl;
            return 0;
        } else {

            for (int i = 0; i < k; i++) {
                int index = 0;
                for (int j = i; j <= maxValue; j = j + k) {
                    result[index] = a[j];
                    index++;
                }
                memset(dp, 0, sizeof(dp));
                dp[0] = result[0];
                for (int j = 1; j < index; j++) {
                    if (j == 1) dp[j] = max(dp[0], result[j]);
                    else dp[j] = max(dp[j - 1], dp[j - 2] + result[j]);
                }

                count += dp[index - 1];
            }
        }

        cout << count << endl;
    }

}
/**
此题思路很吊
首先，将在线用户按比分进行分组，这里我采用一维数组，下标表示比分，值表示该比分的人数，这样，我们就可以把比分相差为K的用户分为若干组【例：K 为2 时 比分为0 2 4 6 8 10... 的用户为1组，1 3 5 7 9 ...的用户为第二组，再例：K为3时： 0 3 6 9...为一组 1 4 7 10...为一组  2 5 8 11为一组（就和希尔排序的分组差不多，只不过我们这里只分一次） 】,这样分完组后，组内元素之间有影响，组与组之间没有影响。
然后，我们会发现，对于每一组，每两个相邻的值只能取一个（因为每两个相邻的元素相差都为K），那么很显然我们要选合适的一个，那怎么才能选合适的呢，这里就要进行动态规划了哈哈
我们这里用 Ai表示第i个人，用dp[i]表示前i个人中最多能得到多少人。对于第i个人只有两种情况，被选，不被选。
被选时： dp[i] = dp[i-2] + Ai;  
不被选：dp[i] = dp[i-1];       
当我们走完某一个分组时，就会得到该分组内能同时在线的最大人数，把每一个分组的最大人数都加一起，就是我们想要的结果了。
注意事项:  当 K =0 时应该单独考虑，因为分不开组，而且只要分数相同的时候就不能同时在线，那么这样的话，我们就只需要遍历我们分组之前建立的数组，就可以得到答案； 
*/
