#include<iostream>
#include<string>

using namespace std;

int main() {
    int len, count;
    int max = -1;
    cin >> len;
    string result = "";
    string s;
    cin >> s;
    int length = s.length();
    for (int i = len; i <= length; i++) {
        for (int j = 0; j <= length - i; j++) {
            string temp = s.substr(j, i);//�Ӵ�����
            count = 0;
            for (int k = 0; k <= length - i; k++) {
                string temp2 = s.substr(k, i);//��ʼͳ��
                if (temp2 == temp) count++;
            }

            if (count > max) {
                max = count;
                result = temp;
            } else if (count == max && result.length() < temp.length()) {
                result = temp;
            }
        }
    }
    cout << result << endl;
}
/*������ٳ������Ӵ� ��ͳ�ƴ��� ˼·�� ����Ҫ�˽�string��� �����api*/
