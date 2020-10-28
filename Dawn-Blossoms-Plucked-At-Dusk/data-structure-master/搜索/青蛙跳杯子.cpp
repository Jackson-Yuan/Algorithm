/**问题描述
　　X星球的流行宠物是青蛙，一般有两种颜色：白色和黑色。
　　X星球的居民喜欢把它们放在一排茶杯里，这样可以观察它们跳来跳去。
　　如下图，有一排杯子，左边的一个是空着的，右边的杯子，每个里边有一只青蛙。


　　*WWWBBB


　　其中，W字母表示白色青蛙，B表示黑色青蛙，*表示空杯子。


　　X星的青蛙很有些癖好，它们只做3个动作之一：
　　1. 跳到相邻的空杯子里。
　　2. 隔着1只其它的青蛙（随便什么颜色）跳到空杯子里。
　　3. 隔着2只其它的青蛙（随便什么颜色）跳到空杯子里。


　　对于上图的局面，只要1步，就可跳成下图局面：


　　WWW*BBB


　　本题的任务就是已知初始局面，询问至少需要几步，才能跳成另一个目标局面。


　　输入为2行，2个串，表示初始局面和目标局面。
　　输出要求为一个整数，表示至少需要多少步的青蛙跳。*/
#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>

using namespace std;
map<string, int> m;
string source, target;
int minValue;

void dfs(string s, int step) {
    if (s == target) {
        if (minValue > step) {
            minValue = step;
        }
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') continue;
        if (i - 1 >= 0 && s[i - 1] == '*') {
            swap(s[i], s[i - 1]);
            if (m[s] == 0) {
                m[s] = 1;
                dfs(s, step + 1);
                m[s] = 0;
            }
            swap(s[i], s[i - 1]);
        }
        if (i + 1 < s.length() && s[i + 1] == '*') {
            swap(s[i], s[i + 1]);
            if (m[s] == 0) {
                m[s] = 1;
                dfs(s, step + 1);
                m[s] = 0;
            }
            swap(s[i], s[i + 1]);
        }
        if (i - 2 >= 0 && s[i - 2] == '*') {
            swap(s[i], s[i - 2]);
            if (m[s] == 0) {
                m[s] = 1;
                dfs(s, step + 1);
                m[s] = 0;
            }
            swap(s[i], s[i - 2]);
        }
        if (i + 2 < s.length() && s[i + 2] == '*') {
            swap(s[i], s[i + 2]);
            if (m[s] == 0) {
                m[s] = 1;
                dfs(s, step + 1);
                m[s] = 0;
            }
            swap(s[i], s[i + 2]);

        }
        if (i - 3 >= 0 && s[i - 3] == '*') {
            swap(s[i], s[i - 3]);
            if (m[s] == 0) {
                m[s] = 1;
                dfs(s, step + 1);
                m[s] = 0;
            }
            swap(s[i], s[i - 3]);
        }

        if (i + 3 < s.length() && s[i + 3] == '*') {
            swap(s[i], s[i + 3]);
            if (m[s] == 0) {
                m[s] = 1;
                dfs(s, step + 1);
                m[s] = 0;
            }
            swap(s[i], s[i + 3]);
        }
    }
}

int main() {
    cin >> source >> target;
    minValue = 0x3f3f3f3f;
    dfs(source, 0);
    cout << minValue << endl;
}
/**
以上为dfs方式 可惜样例都直接超时了
还有最骚的是 在debug阶段 map用数组方式查看值的时候 竟然会有中断异常(debug不支持这种查看方式) 真他妈操了
浪费很长时间 
*/
/**#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	string s;
	int step;
	node(string ss, int tt){
		s = ss;
		step = tt;
	}
};
queue<node> q;
map<string,int> m;
int main(){
	string source, target;
	cin >> source >> target;
	int len = source.length();
	q.push(node(source,0));
	while(!q.empty()){
		node temp = q.front();
		q.pop();
		if(temp.s == target){
			cout<<temp.step<<endl;
			break;
		}
		
		for(int i = 0 ; i < len ; i++){
			if(temp.s[i] == '*'){
			   for(int j = max(0, i - 3) ; j <= min(len - 1 , i + 3) ; j++){
			   	   string ts = temp.s; 
			   	   if(ts[j] != '*'){
			   	   	  swap(ts[j],ts[i]);
			   	   	  if(m[ts] == 0){
			   	   	  	    m[ts] = 1;
			   	   	  	    q.push(node(ts, temp.step + 1));
			   	   	  }
			   	   }
			   }
			}
		}
	}
}*/
/**
此题是广搜的一个经典用例
map的作用相当于做访问标记
queue是广搜的必备工具
如何搜索 找到空杯子的索引 从此位置-3(与0比较)  到此位置+3(与数组长度减1比较) 这个范围遍历这其中的青蛙跳 用map来做访问标记
广搜的好处是 因为广搜是层次遍历 这里面层次就相当于步数 如果用深搜 不是不可以 但会出现比较有多余运算 浪费时间 
*/
