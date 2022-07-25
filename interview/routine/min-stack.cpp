#include "iostream"
#include "stack"

using namespace std;

/**
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 实现 MinStack 类:
 * MinStack() 初始化堆栈对象。
 * void push(int val) 将元素val推入堆栈。
 * void pop() 删除堆栈顶部的元素。
 * int top() 获取堆栈顶部的元素。
 * int getMin() 获取堆栈中的最小元素。
 * 链接：https://leetcode.cn/problems/min-stack
 * */

/**
 * 本题利用一个辅助栈即可达成最小栈的效果。辅助栈的具体操作为：
 * push操作时，判断当前元素是否小于等于栈顶元素，若是压栈
 * 若否，把当前栈顶元素再压一次
 *
 * 这么做的原因：为了保存压入当前元素前，栈内元素的最小值。若小于等于栈顶，则直接压栈，成为新的最小值。
 * 将来弹出时，辅助栈也同步弹出，新的栈顶为，弹出元素后，剩余栈内元素的最小值。若大于，则表明当前压栈元素
 * 无法撼动栈内已有元素的最小值，你这个元素压不压辅助栈对最小值的获取没影响，但为了方便弹出操作的同步性
 * 将栈顶元素重复压一遍
 * */

/**
 * 此外本题还有个不用辅助栈的解法，先留个坑（卷出来的结果）
 * （见官方题解的的评论）
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

