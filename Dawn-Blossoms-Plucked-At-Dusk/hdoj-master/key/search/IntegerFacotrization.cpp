/**
 * 算法笔记 p278
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;
int maxValue;
int n, k, p;
bool token;
vector<int> resPath, path;
int sumRes;
vector<int> number;

void dfs(int index, int sum, int all, int pre) {
    if (index == k) {/**条件判断不能写成index==k && sum == n  /这样可能无法结束递归*/
        if (sum == n && all > sumRes) {
            resPath = path;
            sumRes = all;
            token = true;
        }
        return;
    }
    for (int i = maxValue; i >= 1; --i) {
        if (i <= pre && sum + number[i] <= n) { /**新增一个pre进行剪枝，例如前两个9 8 就不要出现8 9了 因为题目要求字典序要大 出现8 9无意义*/
            path.push_back(i);
            dfs(index + 1, sum + number[i], all + i, i);
            path.pop_back();
        }
    }
    /**for循环这种方式写 可以ac
     * for (int i = pre; i >= 1 ; --i) {
        if (sum + number[i] <= n) {
            path.push_back(i);
            dfs(index + 1, sum + number[i], all + i, i);
            path.pop_back();
        }
    }*/
}

int main() {
    cin >> n >> k >> p;
    maxValue = 0;
    int tmp = 0;
    while (tmp <= n) {
        number.push_back(tmp);
        ++maxValue;
        tmp = (int) pow(maxValue, p);
    }
    maxValue = number.size() - 1;

    token = false;
    sumRes = 0;
    dfs(0, 0, 0, maxValue);
    if (token) {
        cout << n << " = ";
        for (int i = 0; i < resPath.size(); ++i) {
            cout << resPath[i] << "^" << p;
            if (i != resPath.size() - 1) cout << " + ";
        }
        cout << endl;
    } else cout << "Impossible" << endl;

    return 0;
}
/**此题下面的方法全部通过，上面得的方法一个超时，剪枝的策略在于声明个变量保存当前搜素值的总和是否已经超过目标值，超过就不要递归了
 * 其次，因要求字典序大，例如9 8 7如果满足条件那么 7 9 8理论上可以，但字典序大，搜到这种结果就没意义，可以按照下面的方式
 * 每个数选与不选进行操作，也可以按照上面定义一个pre变量，当前位置搜索的变量不得大于pre也可以有相同的效果
 * 至于为什么会超时一个，是循环所致，虽然有两个剪枝条件，但循环的次数没有减少只是减少递归的次数
 * 可以按照上面另外一个注释的for循环写，则可ac
 * */
/**int n, k, p, maxFacsum = -1;
vector<int> fac, ans, tmp;
void init(){
    int i = 0, tmp = 0;
    while (tmp <= n){
        fac.push_back(tmp);
        ++i;
        tmp = (int)pow(i,p);
    }
}

void dfs(int index, int nowK, int sum, int facSum){
    if (sum == n && nowK == k){
        if (facSum > maxFacsum){
            ans = tmp;
            maxFacsum = facSum;
        }
        return;
    }

    if (sum > n || nowK > k) return;

    if (index >= 1){
        tmp.push_back(index);
        dfs(index, nowK + 1, sum + fac[index], facSum + index);选*
        tmp.pop_back();
        dfs(index - 1, nowK, sum, facSum);不选
    }
}

int main(){
    cin >> n >> k >> p;
    init();
    dfs(fac.size() - 1, 0, 0, 0);
    if (maxFacsum == -1) cout << "Impossible" << endl;
    else {
        cout << n << " = ";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << "^" << p;
            if (i != ans.size() - 1) cout << " + ";
        }
        cout << endl;
    }
    return 0;
}**/

