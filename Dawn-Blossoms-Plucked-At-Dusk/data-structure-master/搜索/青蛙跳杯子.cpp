/**��������
����X��������г��������ܣ�һ����������ɫ����ɫ�ͺ�ɫ��
����X����ľ���ϲ�������Ƿ���һ�Ų豭��������Թ۲�����������ȥ��
��������ͼ����һ�ű��ӣ���ߵ�һ���ǿ��ŵģ��ұߵı��ӣ�ÿ�������һֻ���ܡ�


����*WWWBBB


�������У�W��ĸ��ʾ��ɫ���ܣ�B��ʾ��ɫ���ܣ�*��ʾ�ձ��ӡ�


����X�ǵ����ܺ���Щ�ã�����ֻ��3������֮һ��
����1. �������ڵĿձ����
����2. ����1ֻ���������ܣ����ʲô��ɫ�������ձ����
����3. ����2ֻ���������ܣ����ʲô��ɫ�������ձ����


����������ͼ�ľ��棬ֻҪ1�����Ϳ�������ͼ���棺


����WWW*BBB


������������������֪��ʼ���棬ѯ��������Ҫ����������������һ��Ŀ����档


��������Ϊ2�У�2��������ʾ��ʼ�����Ŀ����档
�������Ҫ��Ϊһ����������ʾ������Ҫ���ٲ�����������*/
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
����Ϊdfs��ʽ ��ϧ������ֱ�ӳ�ʱ��
������ɧ���� ��debug�׶� map�����鷽ʽ�鿴ֵ��ʱ�� ��Ȼ�����ж��쳣(debug��֧�����ֲ鿴��ʽ) ���������
�˷Ѻܳ�ʱ�� 
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
�����ǹ��ѵ�һ����������
map�������൱�������ʱ��
queue�ǹ��ѵıر�����
������� �ҵ��ձ��ӵ����� �Ӵ�λ��-3(��0�Ƚ�)  ����λ��+3(�����鳤�ȼ�1�Ƚ�) �����Χ���������е������� ��map�������ʱ��
���ѵĺô��� ��Ϊ�����ǲ�α��� �������ξ��൱�ڲ��� ��������� ���ǲ����� ������ֱȽ��ж������� �˷�ʱ�� 
*/
