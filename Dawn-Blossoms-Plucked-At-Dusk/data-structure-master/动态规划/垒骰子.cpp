/**
题目描述：
赌圣atm晚年迷恋上了垒骰子，就是把骰子一个垒在另一个上边，不能歪歪扭扭，要垒成方柱体。 
经过长期观察，atm 发现了稳定骰子的奥秘：有些数字的面贴着会互相排斥！ 我们先来规范一下骰子：1 的对面是 4，2 的对面是 5，3 的对面是 6。 
假设有 m 组互斥现象，每组中的那两个数字的面紧贴在一起，骰子就不能稳定的垒起来。  atm想计算一下有多少种不同的可能的垒骰子方式。
两种垒骰子方式相同，当且仅当这两种方式中对应高度的骰子的对应数字的朝向都相同。 由于方案数可能过多，请输出模 10^9 + 7 的结果。  
不要小看了 atm 的骰子数量哦～  
「输入格式」 
第一行两个整数 n m n表示骰子数目 
接下来 m 行，每行两个整数 a b ，表示 a 和 b 数字不能紧贴在一起。  
「输出格式」 
一行一个数，表示答案模 10^9 + 7 的结果。  
「样例输入」 
 2 1
 1 2  
「样例输出」 544  
「数据范围」 
对于 30% 的数据：n <= 5 对于 60% 的数据：n <= 100 
对于 100% 的数据：0 < n <= 10^9, m <= 36   
资源约定： 
峰值内存消耗 < 256M CPU消耗  < 2000ms   
请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。  
所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。  
注意: main函数需要返回0 
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。  
提交时，注意选择所期望的编译器类型。
*/
#include<iostream>
#include<string.h>
#include<map>

using namespace std;

long long pow(long long a, long long b) {
    long long base = a;
    long long sum = 1;
    while (b) {
        if (b & 1 == 1) sum *= base;
        base *= base;
        b = b >> 1;
    }

    return sum;

}//a^b
bool conflict[7][7];
map<int, int> mm;
int dp[101][7];//第i层 数字j朝上 
void init() {
    mm[1] = 4;
    mm[2] = 5;
    mm[3] = 6;
    mm[4] = 1;
    mm[5] = 2;
    mm[6] = 3;
}

int main() {
    int n, m;
    cin >> n >> m;
    init();
    memset(conflict, 0, sizeof(conflict));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }

    for (int i = 1; i <= 6; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i][j] = 0;
            for (int k = 1; k <= 6; k++) {
                if (!conflict[mm[k]][j]) dp[i][j] += dp[i - 1][k];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += dp[n][i];
    }

    cout << ans * pow(4, n) << endl;
}
/**
/**#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int count;
int n;
int sum;
bool conflict[7][7];
int num[7];
void dfs(int index, int pre){
	if(index == n){
		count++;
		count %= 1000000007;
		return;
	}
	
	for(int i = 1 ; i <= 6 ; i++){
		if(index == 0){
		   dfs(index + 1, i);
		}else{
			if(!conflict[num[pre]][i]){
				dfs(index + 1, i);
			}
		}
	}
}
int main(){
	int m;
	cin >> n >> m;
	num[1] = 4;
	num[2] = 5;
	num[3] = 6;
	num[4] = 1;
	num[5] = 2;
	num[6] = 3;
	sum = 1;
	for(int i = 0 ; i < n ; i++){
		sum *= 4;
	}
	memset(conflict, 0, sizeof(conflict));
	for(int i = 0 ; i < m ; i++){
		int a, b;
		cin >> a >> b;
		conflict[a][b] = true;
		conflict[b][a] = true;
	}
	
	count = 0;
	dfs(0, 0);
	cout << count << endl;
	cout << count * sum << endl;
}*/
/**
此题注释部分代码为暴力代码 思路容易理解 就是简单的暴力搜索所有摆放情况 第一个都有6种方向  以后的摆放都要考虑是否互斥
但此方法会直接超时
不妨换种思路 一般求最值 暴力法 动态规划 贪心
此题贪心肯定不现实 应该用动态规划
建立二维dp数组 行表示垒的层数，列表示哪个面朝上
很显然 摆第一层时 j的所有情况都为1  层数大于1之后 每个j的情况都由下一层来决定(排除互斥面朝上的情况，其余累加即可) 
*/
