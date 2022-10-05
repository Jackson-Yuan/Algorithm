#include "iostream"
#include "queue"
#include "vector"

/**
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 例如，
 * [2,3,4]的中位数是 3
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 设计一个支持以下两种操作的数据结构：
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 链接：https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
 * */

/**
 * 本题思路，最简单的，获取当前数据流的数，排序或者寻找2/k位置的数
 * 但这个不符合应用场景，因为数据流每来一个新的数，都要重新排序，或者重新寻找2/k
 * 这边利用一个最大堆left，最小堆right，最大堆表示中位数左边的部分，最小堆表示中位数最大的部分
 * 我们规定：
 * 1、当left与right包含的数相等时，中位数为两个堆顶数的平均值
 * 2、当left包含的数比right多1时，中位数为left堆顶元素（也可以规定right比left多1）
 *
 * 根据这个规定，制定相应添加策略
 *
 * 当要添加一个新数num时，若left==right，则判断num是否小于等于right的堆顶，小于直接直接向left添加（为了保持left比right大1）
 * 否则先将right的堆顶放入left，并弹出right堆顶，放入num
 *
 * 当left!=right（必为left比right大1），若num大于等于left堆顶，直接塞入right，否则先将left堆顶塞入right，弹出left堆顶
 * 放入num
 * */


using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> qMax;
    priority_queue<int, vector<int>, greater<int>> qMin;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (qMax.size() == qMin.size()) {
            if (qMin.empty() || num <= qMin.top()) qMax.push(num);
            else {
                qMax.push(qMin.top());
                qMin.pop();
                qMin.push(num);
            }
        } else {
            if (num >= qMax.top()) qMin.push(num);
            else {
                qMin.push(qMax.top());
                qMax.pop();
                qMax.push(num);
            }
        }
    }

    double findMedian() {
        if (qMax.size() == qMin.size()) {
            return (qMin.top() + qMax.top()) / 2.0;
        } else return qMax.top();
    }
};
