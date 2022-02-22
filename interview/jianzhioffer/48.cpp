#include "iostream"
#include "string"
#include "map"

using namespace std;

/**
 * ������ظ��ַ����Ӵ�
 * ��Ȼ���÷ֽ�С���������⣬�ö�̬�滮�������������£�
 * �ӵ�һ���ַ���ʼ��������ʼ�������������г���һ���ַ�������λ��j����֮ǰ���ֹ�
 * �������ظ��ַ�֮��ľ���d�����ȿ�j-1λ�õ��Դ�λ��Ϊ����������ظ��Ӵ��Ƕ೤��
 * ��d��������˵���������ǿ��ǵķ�Χ�ڣ�j-1λ�õĳ���ֱ�Ӹ�ֵ��j����С�ڵ��ڣ������
 * �ظ��ַ��������Դ�j-1λ��Ϊ����������ظ��Ӵ��У���jλ�õĵĳ���Ϊd��
 * ÿ����һ���㣬�������ֵ���ж�
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        map<char, int> m;
        int ans = -1;
        int cur = 0;
        for (int i = 0; i < s.length(); ++i) {
            auto ite = m.find(s[i]);

            if (ite == m.end()) {
                ++cur;
            } else {
                int d = i - ite->second;
                if (d <= cur) cur = d;
                else ++cur;
            }

            m[s[i]] = i;
            if (cur > ans) ans = cur;
        }

        return ans;
    }
};

