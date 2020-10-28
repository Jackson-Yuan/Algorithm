/**
abcacca�г��������������ac��


a_c____


a___c__


a____c_


___ac__


___a_c_

*/

#include<iostream>
#include<string.h>

using namespace std;

/**int num(string S, string T){
	if (S.length() == 0) {  
      return T.length() == 0 ? 1 : 0;  
    }  
    if (T.length() == 0) {  
       return 1;  
    }  
     int cnt = 0;  
   for (int i = 0; i < S.length(); i++) {  
    if (S.at(i) == T.at(0)) {  
       cnt += num(S.substr(i + 1), T.substr(1));  
     }  
   }  
  return cnt;  
}
int main(){
	string a,b;
	cin >> a >> b;
	cout<<num(a, b)<<endl;
}*/
int num(string S, string T) {
    if (S.empty() || T.empty()) return 0;
    if (S.length() < T.length()) return 0;
    int dp[T.length() + 1][S.length() + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= T.length(); i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= S.length(); j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= T.length(); i++) {
        for (int j = 1; j <= S.length(); j++) {
            dp[i][j] = dp[i][j - 1];
            if (T[i - 1] == S[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[T.length()][S.length()];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << num(a, b) << endl;
}
/*
�����������������ʽ ֱ�ӱ�������������� (ע�Ͳ��� ����˼·��ȷ��������û�뵽���� ����~~~~)
������һ�㶼��ʱ
���Կ��Ƕ�̬�滮(�Ӵ����� һ�㶼��̬�滮) dp[i][j] ����Ϊiƥ��j���ַ����ĸ���
��ʵ˼·�ܼ� dp[i][j] = dp[i][j - 1] �����s[i] == t[i]�ٶ����1(���� Ҫ�ó��ȼ�ȥһ) 
����ô���� ����~~~~ 
*/
