/**
��������
�ܾ���ǰ��T������ǰ���١�Ϊ�˸��õع�����ң������޽��˴����Ŀ���·�����������׶��������ڵĸ�����С�
Ϊ��ʡ���ѣ�T���Ĵ��Ǿ���˼�����ƶ���һ��������޽�������ʹ���κ�һ������ж��ܴ��׶�ֱ�ӻ���ͨ����������м�ӵ��ͬʱ��������ظ���������У����׶�����ÿ������еķ�������Ψһ�ġ�
J��T����Ҫ�󳼣���Ѳ���ڸ������֮�䣬������顣���ԣ���һ��������ͣ��ص���һ�����г���J��������顣����һ��Ǯ�������ڴ���������м��·�ѡ�
������J���֣��������ĳ������ͣ�����������������н������У���������·���������߹��ľ����йأ����ߵ�xǧ�׵���x+1ǧ����һǧ���У�x���������������ѵ�·����x+10��ô�ࡣҲ����˵��1ǧ�׻���11����2ǧ��Ҫ����23��
J����֪��������ĳһ�����г������м䲻��Ϣ��������һ�����У����п��ܻ��ѵ�·��������Ƕ����أ�
�����ʽ
����ĵ�һ�а���һ������n����ʾ�����׶����ڵ�T�����ĳ�����
���д�1��ʼ���α�ţ�1�ų���Ϊ�׶���
������n-1�У�����T���ĸ���·��T���ĸ���·һ����n-1����
ÿ����������Pi, Qi, Di����ʾ����Pi�ͳ���Qi֮����һ������·������ΪDiǧ�ס�
�����ʽ
���һ����������ʾ��J��໨�ѵ�·���Ƕ��١�
��������1
5
1 2 2
1 3 1
2 4 5
2 5 4
�������1
135 
�����ʽ
��J�ӳ���4������5Ҫ����135��·�ѡ�
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

int getSum(int start, int end) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += i + 10;
    }
    return sum;
}

struct node {
    int target;
    int cost;
};
vector<struct node> grap[10001];
int maxValue;
bool vis[10001];
int index;

void dfs(int location, int length, int start) {
    if (length > maxValue) {
        index = location;
        maxValue = length;
    }
    vis[location] = true;
    for (int i = 0; i < grap[location].size(); i++) {
        if (!vis[grap[location][i].target]) {
            dfs(grap[location][i].target, length + grap[location][i].cost, start + grap[location][i].cost);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        struct node tmp;
        tmp.target = b;
        tmp.cost = c;
        grap[a].push_back(tmp);
        tmp.target = a;
        grap[b].push_back(tmp);
    }

    memset(vis, 0, sizeof(vis));
    maxValue = -1;
    index = 0;
    dfs(1, 0, 0);
    memset(vis, 0, sizeof(vis));
    dfs(index, 0, 0);

    cout << ((11 + 10 + maxValue) * maxValue) / 2 << endl;
    return 0;
}
/**
������ֱ������
����ֱ�� ��һ������ ��ĳ�㵽ĳ���Ȩֵ֮����� ���巽��Ϊ �ȴ�ĳ��p dfs����˵������ĵ�q Ȼ���q��������ĵ�g qg��Ϊ����ֱ��
���õ�����Ϊ��������һ�㵽�������Զ�ĵ㶼��ֱ���� 
*/
