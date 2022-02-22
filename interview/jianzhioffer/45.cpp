#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;


/**
 *
 * ��ѧԭ���� ���ɸ��� ���г���С����
 *
 * ԭ��Ϊ���������������
 * �����x��y  ��xy < yx(xy����Ϊƴ�ӵ���)����x < y
 *
 * ���մ˴�С�������� ֱ��ƴ�Ӿ��ǽ��
 * */
bool cmp(string &a, string &b) {
    string a_head = a + b;
    string b_head = b + a;
    return a_head < b_head;
}

class Solution {
public:
    string minNumber(vector<int> &nums) {
        vector<string> nums_str;
        for (int cur : nums) {
            nums_str.push_back(to_string(cur));
        }

        sort(nums_str.begin(), nums_str.end(), cmp);

        string ans;

        for (string cur : nums_str) {
            ans += cur;
        }

        return ans;
    }
};

int main() {
    string a = "1";
    string b = "2";

    cout << (a < b);
}