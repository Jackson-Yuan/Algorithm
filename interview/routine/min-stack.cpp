#include "iostream"
#include "stack"

using namespace std;

/**
 * ���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
 * ʵ�� MinStack ��:
 * MinStack() ��ʼ����ջ����
 * void push(int val) ��Ԫ��val�����ջ��
 * void pop() ɾ����ջ������Ԫ�ء�
 * int top() ��ȡ��ջ������Ԫ�ء�
 * int getMin() ��ȡ��ջ�е���СԪ�ء�
 * ���ӣ�https://leetcode.cn/problems/min-stack
 * */

/**
 * ��������һ������ջ���ɴ����Сջ��Ч��������ջ�ľ������Ϊ��
 * push����ʱ���жϵ�ǰԪ���Ƿ�С�ڵ���ջ��Ԫ�أ�����ѹջ
 * ���񣬰ѵ�ǰջ��Ԫ����ѹһ��
 *
 * ��ô����ԭ��Ϊ�˱���ѹ�뵱ǰԪ��ǰ��ջ��Ԫ�ص���Сֵ����С�ڵ���ջ������ֱ��ѹջ����Ϊ�µ���Сֵ��
 * ��������ʱ������ջҲͬ���������µ�ջ��Ϊ������Ԫ�غ�ʣ��ջ��Ԫ�ص���Сֵ�������ڣ��������ǰѹջԪ��
 * �޷�����ջ������Ԫ�ص���Сֵ�������Ԫ��ѹ��ѹ����ջ����Сֵ�Ļ�ȡûӰ�죬��Ϊ�˷��㵯��������ͬ����
 * ��ջ��Ԫ���ظ�ѹһ��
 * */

/**
 * ���Ȿ�⻹�и����ø���ջ�Ľⷨ���������ӣ�������Ľ����
 * �����ٷ����ĵ����ۣ�
 * */
class MinStack {
private:
    stack<int> val;
    stack<int> helper;
public:
    MinStack() {
    }

    void push(int val) {
        this->val.push(val);

        if (helper.empty() || helper.top() >= val) {
            helper.push(val);
        } else {
            helper.push(helper.top());
        }
    }

    void pop() {
        val.pop();
        helper.pop();
    }

    int top() {
        return val.top();
    }

    int getMin() {
        return helper.top();
    }
};

