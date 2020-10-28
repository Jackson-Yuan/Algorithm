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

int judge(char character, char compare) {//character > compare真 小于等于假
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
    //生成后缀表达式
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
    /*将剩余的弹出 压s1栈*/
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
此题就是利用三个栈实现算术表达式的求值 
一个栈保存加减乘除左右括号 一个栈保存数值 
另外一个栈保存计算值

压数的栈 直接压 不bb 但注意由于是字符串形式 两位数以上不好直接压 应该用#分隔
来代表不同的数
压操作符的栈 有几种考虑情况
第一个是栈空 直接压 左括号 直接压
所要压的操作符优先级大于栈顶的操作符优先级 直接压

如果碰到右括号
则弹出栈顶元素 压入放数的栈 直到弹出左括号 左括号和右括号不入栈
如果所要压的操作符比栈顶元素优先级低 则弹出 压入数栈 直到遇到比栈顶元素高(不弹出)
压栈 
此处注意:
while(!s2.empty() && !judge(str[i], s2.top()) ){
					char temp = s2.top();
					s1.push(temp);
					s2.pop();
				}
循环判断条件 中两个顺序不能颠倒
因为&& 是从左向右 如果 右边的放到左边 那么当栈恰好为空时 则会报错


等算式表达式遍历完后 把操作符栈的操作符直接压进数栈
那么数栈的倒叙即为后缀表达式
利用后缀表达式 压入计算值栈 是数就压 是操作符 就弹出前两个 根据操作符算出结果 压栈
直到遍历完 那么计算值栈中的栈顶就是最后结果 
*/
