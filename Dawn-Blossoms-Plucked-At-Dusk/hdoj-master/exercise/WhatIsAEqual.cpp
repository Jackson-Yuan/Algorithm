/**
 * 有如下方程：Ai = (Ai-1 + Ai+1)/2 - Ci (i = 1, 2, 3, .... n).
 * 若给出A0, An+1, 和 C1, C2, .....Cn.
 * 请编程计算A1 = ?
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        double a, b;
        cin >> a >> b;
        vector<double> c(n, -1);
        for (int i = 0; i < c.size(); ++i) {
            cin >> c[i];
        }

        double right = 0;
        right += n * a;
        right += b;
        double tmpRight = 0;
        for (int i = 0; i < c.size(); ++i) {
            tmpRight += (n - i) * c[i];
        }

        tmpRight *= 2;
        right -= tmpRight;
        printf("%.2lf\n", right / (n + 1));
    }
    return 0;
}
/**
 * 因为：Ai=(Ai-1+Ai+1)/2 - Ci,
      A1=(A0  +A2  )/2 - C1;
      A2=(A1  +  A3)/2 - C2 , ...
      A1+A2 = (A0+A2+A1+A3)/2 - (C1+C2)
     A1+A2 =  A0+A3 - 2(C1+C2)
同理可得：
      A1+A1 =  A0+A2 - 2(C1)
      A1+A2 =  A0+A3 - 2(C1+C2)
      A1+A3 =  A0+A4 - 2(C1+C2+C3)
      A1+A4 =  A0+A5 - 2(C1+C2+C3+C4)
      ...
      A1+An = A0+An+1 - 2(C1+C2+...+Cn) 我仅仅到了这一步就结束了
----------------------------------------------------- 左右求和
     (n+1)A1+(A2+A3+...+An) = nA0 +(A2+A3+...+An) + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

=>   (n+1)A1 = nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

=>   A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1)
*/
