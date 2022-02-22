#include "iostream"
#include "vector"

using namespace std;


/**
 *  ������Ҫ��϶�����������������������ص㣨���ڵ������һ������Ͻ��
 *  �ټ������Ӽ���
 * */
class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        if (postorder.size() == 0) return true;

        return judge(postorder, 0, postorder.size() - 1);
    }

    bool judge(vector<int> &num, int start, int end) {
        if (start >= end) return true;

        int root = num[end];
        int left_start = start, right_start = start;

        bool left = true, right = true;
        if (num[start] < root) {
            while (right_start < end && num[right_start] < root) ++right_start;

            for (int i = left_start; i < right_start; ++i) {
                if (num[i] > root) {
                    left = false;
                    break;
                }
            }

            for (int i = right_start; i < end; ++i) {
                if (num[i] < root) {
                    right = false;
                    break;
                }
            }
        } else {
            for (int i = right_start; i < end; ++i) {
                if (num[i] < root) {
                    right = false;
                    break;
                }
            }
        }

        if (left && right) return judge(num, left_start, right_start - 1) && judge(num, right_start, end - 1);
        else return false;
    }
};