/**
 * 给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]
 * 形式上，斐波那契式序列是一个非负整数列表 F，且满足：
 * 0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
 * F.length >= 3；
 * 对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
 * 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
 * 返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。
 * */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        if (S.length() < 3) return ans;
        dfs(ans, S, S.length(), 0, 0, 0);
        return ans;
    }


    /**
     * 利用深搜回溯暴力搜索每种情况
     * 当然也有必要的剪枝策略
     * dfs函数参数大致执行流程：
     * 每一次递归，从开始索引即index开始 构造本轮递归要求的数
     * 若index值正好等于length，即判断ans数组元素是否大于等于三个
     * 否则构造数，有三个剪枝策略：
     * 如本轮递归的index对应的值为0，则只需判断index单个即可，不需要判断index之后的数（交给下一轮递归，注意：虽然不交给下一轮递归，
     * 算出来值不影响，但会影响判断 如“0123”）
     * 又因为一轮递归构造的数不可能大于INT_MAX,过了直接break，后面的直接不考虑
     * 每轮递归都会保留ans数组最后两个值的和，若此轮构造的数已经大于此轮保存的两个值的和，直接break，后面的直接不考虑
     * 这样三轮判断下来，会大大减少递归次数
     * */
    bool dfs(vector<int> &ans, string str, int length, int index, long long sum, int pre) {
        if (index == length) return ans.size() >= 3;

        long long cur = 0;
        for (int i = index; i < length; ++i) {
            if (i > index && str[index] == '0') break;

            cur = cur * 10 + str[i] - '0';
            if (cur > INT_MAX) break;

            if (ans.size() >= 2) {
                if (cur < sum) continue;
                if (cur > sum) break;
            }
            ans.push_back(cur);
            if (dfs(ans, str, length, i + 1, cur + pre, cur)) return true;
            ans.pop_back();
        }

        return false;
    }
};
/**
 * 详情见注释
 * */