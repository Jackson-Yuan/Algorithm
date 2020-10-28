/**
 * 汉诺塔原型题解法
 * */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    vector<int> num = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023};
    vector<int> array;
    vector<int> tmp;
    tmp.push_back(1);
    array.push_back(1);
    for (int i = 1; i < 10; ++i) {
        int tmpValue = 2 * tmp[i - 1] + 1;
        array.push_back(tmpValue);
        tmpValue = array[i - 1] + 1 + tmp[i - 1];
        tmp.push_back(tmpValue);
    }

    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << ",";
    }
    return 0;
}
/**
 * 汉诺塔最初公式为2 * array[i - 1] + 1
 * 其次array数组的意义为圈数为n时需要摆放的次数
 * 但这个式子与实际操作对应起来似乎很难理解
 * 所以这里介绍另外一种解法
 * 因为移动次数最佳选择思路：
 * 例如移动n个圈，先将n-1一个圈移动至中间一根柱
 * 再将第n个移至最右柱，再将中间的n-1个移至最右
 * 所以说递推的关键在于左到中，中到右的次数为多少
 * 因左到中，中到右，都是相邻柱子移动，且都需借助额外的柱子进行辅助
 * 所以它俩次数应该是一样的，所以不妨求左到中
 * n个圈移至中，先将n-1个移至最左边(相当于前n-1个做了次汉诺塔操作)，
 * 然后第n个移至中间，然后最左边n-1个移至中间，相当于n-1个圈移至相邻的次数(若理解不了，可以更换柱子的地位,目标柱？辅助柱？)，递推显现
 * */