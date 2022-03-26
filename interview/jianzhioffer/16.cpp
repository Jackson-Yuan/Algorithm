#include "istream"

using namespace std;


/**
 * �����ݵ�ʹ��
 * �Լ�������ָ�������������߽�Ĵ���
 * �����߽�-2147483648ת�������£�ֱ���޷�����ǿת
 * ����ȡ����ת��ȡ��Ҳ����ȡ��ʹ����int�ͣ�����Χ�ˣ�
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

