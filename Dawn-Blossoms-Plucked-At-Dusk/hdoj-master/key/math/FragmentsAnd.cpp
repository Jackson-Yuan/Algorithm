/**
 * 算法笔记 p195
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
    cin >> n;
    vector<double> res(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }

    double ans = 0;
    for (int i = 0; i < res.size(); ++i) {
        int location = i + 1;
        ans += res[i] * location * (n + 1 - location);
        /**
         * ans += 1.0 * location * (n + 1 - location) * res[i];
         * */
    }
    printf("%.2lf\n", ans);

    return 0;

}
/**
 * 此题就是找规律题 这种规律随缘吧
 * 但有一个坑点 如注释部分，若去掉1.0会判错，究其原因是double型范围比int大，而数据范围给到100000
 * 如100000 * 100000 给int型变量，直接溢出，给double型则完全没有问题
 * 但不能这么给double a = 100000 * 100000 这样给依然错的，以为等式右边先算，是个int型数据赋值之前就已经超了
 * 应该给两个100000至少一个转成double，可以用强转，也可以乘以0.1
 * 但0.1乘的位置值得注意，若是100000 * 100000 * 0.1 不好意思依然不对，因为*号自左至有结合，他依然会先算100000 * 100000
 * 这样会先是个溢出的int型再乘以一个double型，所以1.0乘了没有起作用
 * 但若这样写1.0 * 100000 * 100000 则没问题，因为先算1.0 * 100000 double与int乘自动转成double，所以式子最终变成一个double型的100000乘以
 * int型的100000，这样就不会出错，所以回到题目，去掉1.0报错就是因为结合顺序转型转晚了，结果溢出gg
 * 比较细节
 * */