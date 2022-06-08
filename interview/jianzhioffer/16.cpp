#include "istream"

using namespace std;


/**
 * 快速幂的使用
 * 以及对正负指数处理，及负数边界的处理
 * 负数边界-2147483648转成正数事，直接无符号数强转
 * 无需取反再转（取反也报错，取反使还算int型，超范围了）
 * */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        } else {
            bool isReverse = false;
            unsigned int realN;
            if (n < 0) {
                isReverse = true;
                if (n != -2147483648) realN = (unsigned int) (-n);
                else realN = (unsigned int) n;
            } else realN = (unsigned int) n;

            double ans = 1;
            while (realN) {
                if (realN & 1) ans *= x;
                x *= x;
                realN >>= 1;
            }

            if (isReverse) return 1 / ans;
            else return ans;
        }
    }
};

