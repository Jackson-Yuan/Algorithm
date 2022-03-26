#include "iostream"
#include "vector"
#include "string"
#include "set"

using namespace std;

/**
 * ����һ�����������ź���ĸ��ɵ��ַ��� s ��ɾ����С��������Ч���ţ�ʹ��������ַ�����Ч��
 * �������п��ܵĽ�����𰸿��԰� ����˳�� ���ء�
 * */

/**
 * ����ͨ�������ַ���ͳ����Ҫ��Сɾ��������������������
 *
 * Ȼ��ʼ��������
 *
 * ע�����������ѷ�ʽ�����Ѷ�
 * ͨ��ɾ��ĳ�����ţ��������Ҵ������¸�״̬��������
 * ͬʱ����֦����ֵ������
 * */
class Solution {
private:
    set<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftCount = 0, rightCount = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++leftCount;
            } else if (s[i] == ')') {
                ++rightCount;
                if (leftCount > 0) {
                    --leftCount;
                    --rightCount;
                }
            }
        }

        vector<string> res;

        ans.clear();
        dfs(s, 0, leftCount, rightCount);
        auto ite = ans.begin();
        while (ite != ans.end()) {
            res.push_back(*ite);
            ++ite;
        }
        return res;
    }


    void dfs(string &s, int start, int leftCount, int rightCount) {
        if (leftCount == 0 && rightCount == 0) {
            if (isValid(s)) {
                ans.insert(s);
            }

            return;
        }


        for (int i = start; i < s.length(); ++i) {

            if (leftCount + rightCount > s.length() - i) return;

            if (leftCount > 0 && s[i] == '(') {
                string cur = s.substr(0, i) + s.substr(i + 1);
                dfs(cur, i, leftCount - 1, rightCount);
            }

            if (rightCount > 0 && s[i] == ')') {
                string cur = s.substr(0, i) + s.substr(i + 1);
                dfs(cur, i, leftCount, rightCount - 1);
            }
        }
    }


    bool isValid(string &cur) {
        int leftCount = 0, rightCount = 0;

        for (int i = 0; i < cur.length(); ++i) {
            if (cur[i] == '(') {
                ++leftCount;
            } else if (cur[i] == ')') {
                ++rightCount;
                if (leftCount > 0) {
                    --leftCount;
                    --rightCount;
                } else return false;
            }
        }

        return leftCount == 0 && rightCount == 0;
    }

};