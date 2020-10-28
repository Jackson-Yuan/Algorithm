#include<stdio.h>
#include<stack>
#include<string.h>
#include<iostream>
#include<math.h>

using namespace std;
char str[1000];
char value[1000];
char num[100];
stack<char> s1, s2;
stack<int> s3;

int judge(char character, char compare) {//character > compare�� С�ڵ��ڼ�
    if (character == '*' || character == '/') {
        if (compare == '*' || compare == '/') return 0;
        else return 1;
    } else if (character == '+' || character == '-') {
        if (compare == '(' || compare == ')') return 1;
        else return 0;
    } else if (character == '(' || character == ')') return 0;
}

int main() {
    scanf("%s", &str);
    int sum = strlen(str);
    //���ɺ�׺���ʽ
    for (int i = 0; i < sum; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (i + 1 < sum && (str[i + 1] >= '0' && str[i + 1] <= '9')) {
                s1.push(str[i]);
            } else {
                s1.push(str[i]);
                s1.push('#');
            }
        } else {
            if (s2.empty() || str[i] == '(' || (!s2.empty() && judge(str[i], s2.top()))) {
                s2.push(str[i]);
            } else if (str[i] == ')') {
                while (s2.top() != '(') {
                    char temp = s2.top();
                    s1.push(temp);
                    s2.pop();
                }
                s2.pop();
            } else if (!judge(str[i], s2.top())) {
                while (!s2.empty() && !judge(str[i], s2.top())) {
                    char temp = s2.top();
                    s1.push(temp);
                    s2.pop();
                }
                s2.push(str[i]);
            }
        }
    }
    /*��ʣ��ĵ��� ѹs1ջ*/
    while (!s2.empty()) {
        char temp = s2.top();
        s2.pop();
        s1.push(temp);
    }
    int index = 0;
    while (!s1.empty()) {
        value[index] = s1.top();
        index++;
        s1.pop();
    }
    int count = 0;
    for (int i = index - 1; i >= 0; i--) {
        if (value[i] == '#') continue;
        if (value[i] >= '0' && value[i] <= '9') {
            num[count] = value[i];
            count++;
            if (i - 1 >= 0 && value[i - 1] == '#') {
                int tempValue = count - 1;
                int sum = 0;
                for (int j = 0; j < count; j++) {
                    sum += (num[j] - '0') * pow(10, tempValue);
                    tempValue--;
                }
                s3.push(sum);
                count = 0;
            }
        } else if (value[i] == '+') {
            int a = s3.top();
            s3.pop();
            int b = s3.top();
            s3.pop();
            int sum = b + a;
            s3.push(sum);
        } else if (value[i] == '-') {
            int a = s3.top();
            s3.pop();
            int b = s3.top();
            s3.pop();
            int sum = b - a;
            s3.push(sum);
        } else if (value[i] == '*') {
            int a = s3.top();
            s3.pop();
            int b = s3.top();
            s3.pop();
            int sum = b * a;
            s3.push(sum);
        } else if (value[i] == '/') {
            int a = s3.top();
            s3.pop();
            int b = s3.top();
            s3.pop();
            int sum = b / a;
            s3.push(sum);
        }
    }
    printf("%d\n", s3.top());
}
/*
���������������ջʵ���������ʽ����ֵ 
һ��ջ����Ӽ��˳��������� һ��ջ������ֵ 
����һ��ջ�������ֵ

ѹ����ջ ֱ��ѹ ��bb ��ע���������ַ�����ʽ ��λ�����ϲ���ֱ��ѹ Ӧ����#�ָ�
������ͬ����
ѹ��������ջ �м��ֿ������
��һ����ջ�� ֱ��ѹ ������ ֱ��ѹ
��Ҫѹ�Ĳ��������ȼ�����ջ���Ĳ��������ȼ� ֱ��ѹ

�������������
�򵯳�ջ��Ԫ�� ѹ�������ջ ֱ������������ �����ź������Ų���ջ
�����Ҫѹ�Ĳ�������ջ��Ԫ�����ȼ��� �򵯳� ѹ����ջ ֱ��������ջ��Ԫ�ظ�(������)
ѹջ 
�˴�ע��:
while(!s2.empty() && !judge(str[i], s2.top()) ){
					char temp = s2.top();
					s1.push(temp);
					s2.pop();
				}
ѭ���ж����� ������˳���ܵߵ�
��Ϊ&& �Ǵ������� ��� �ұߵķŵ���� ��ô��ջǡ��Ϊ��ʱ ��ᱨ��


����ʽ���ʽ������� �Ѳ�����ջ�Ĳ�����ֱ��ѹ����ջ
��ô��ջ�ĵ���Ϊ��׺���ʽ
���ú�׺���ʽ ѹ�����ֵջ ������ѹ �ǲ����� �͵���ǰ���� ���ݲ����������� ѹջ
ֱ�������� ��ô����ֵջ�е�ջ����������� 
*/
