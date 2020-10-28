/**
有一天，他在宿舍里无意中发现了一个天平！这  个天平很奇怪，有n个完好的砝码，但是没有游码。盾神为他的发现兴奋不已！于是他准备去称一称自己的东西。
他准备好了m种物品去称。神奇的是，盾神一早就  知道这m种物品的重量，他现在是想看看这个天平能不能称出这些物品出来。
但是盾神稍微想了1秒钟以后就觉得这个问题太无聊了，于是就丢给了你。 数据规模和约定 1< =n< =24,  1< =m< =10. 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>

using namespace std;
int n, m, flag;
int sum[24];
int fm[24];
int wp[24];

void dfs(int difference, int index) {/**物一侧与物品对面重量之和的差值， 选取的砝码*/
    if (flag == 1) return;
    if (abs(difference) > sum[index]) return;
    if (difference == 0 || abs(difference) == sum[index]) {
        flag = 1;
        return;
    }
    if (index < 0) return;
    dfs(difference - fm[index], index - 1);
    dfs(difference, index - 1);
    dfs(difference + fm[index], index - 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> fm[i];
        if (i > 0) {
            sum[i] = sum[i - 1] + fm[i];
        } else sum[i] = fm[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> wp[i];
    }

    for (int i = 0; i < m; i++) {
        flag = 0;
        int target = wp[i];
        dfs(target, n - 1);
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
/**
此题理解题意 后就是个搜索 遍历砝码的组合情况来与物品大小进行比较
但上下两个方法 上面的过了90%的数据 下面的直接超时  其原因在于搜索方式不同 
下面的搜索方式 其实是砝码的全排列形式 暴力算出结果
上面的是利用每个砝码的摆放可能来搜索， 分三种 摆在物品对面 摆在物品一侧 不摆三种情况
如果这样搜 那么也仅仅只能过一半的测试用例， 这是sum数组起到了优化的作用 利用sum数组保存前i个砝码
的重量和 在搜索过程中 判断差值是否大于剩余的砝码之和 大于则肯定不成立 若等于 则也不必继续搜索 肯定能行 这样就起到 了优化的作用 
*/
/**int target, flag;
int n, m;
int fm[26];
int wp[26];
int visited[24];
void dfs(int sum){
	if(flag == 1) return;
	
	if(sum == target){
		flag = 1;
		return;
	}
	for(int i = 0 ; i < n ; i++){
		if(visited[i] == 0){
			visited[i] = 1;
			dfs(sum + fm[i]);
			if(sum >= fm[i]){
				dfs(sum - fm[i]);
			}
			visited[i] = 0;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> fm[i];
	}
	for(int i = 0 ; i < m ; i++){
		cin >> wp[i];
	}
	for(int i = 0 ; i < m ; i++){
		memset(visited,0,sizeof(visited));
		target = wp[i];
		flag = 0;
		dfs(0);
		if(flag == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}*/
