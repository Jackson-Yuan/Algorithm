#include "iostream"
#include "vector"

using namespace std;
/**
 * ����һ��������ɫ����ɫ����ɫ����n ��Ԫ�ص�����nums��ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�
 * ����ʹ������ 0��1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
 * �����ڲ�ʹ�ÿ��sort����������½��������⡣
 * ������һ����ʹ�ó����ռ��һ��ɨ���㷨
 * ���ӣ�https://leetcode-cn.com/problems/sort-colors
 * */

/**
 * ������򵥵���������ֱ��������
 * ������ĿҪ��һ�α��������ע�⵽�����������Ԫ���ǹ̶��ģ����Ϊ���Ҫ���ṩ����
 * �ⷨ��ʵ�ܼ򵥣���������Ԫ���ǹ̶���0��1��2������һ��ɨ��ֱ��0��1���н�������
 * */
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

