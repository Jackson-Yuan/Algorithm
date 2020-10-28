#include<stdio.h>

char str[8000];
int n;

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &str[i]);
    }
    int count = 0;
    int extra = 0;
    int flag = 0;
    char preserveTemp;
    int end = n - 1;
    for (int i = 0; i < end; i++) {
        for (int j = end; j >= 0; j--) {
            /*如果从末尾寻找的数 如果与i重合了 那么证明没有数跟他配对*/
            if (i == j) {
                /*有一个还行 两个就gg 并且有一个的情况下 还得是长度为奇数 不然又gg*/
                flag++;
                if (n % 2 == 0 || flag > 1) {
                    printf("Impossible\n");
                    return 0;
                }
                /*没匹配的数放中间 */
                extra = n / 2 - i;
                break;
            } else if (str[i] == str[j]) {
                count += end - j;
                for (int z = j; z < end; z++) {
                    str[z] = str[z + 1];
                }
                str[end] = str[i];
                end--;
                break;
            }
        }
    }
    printf("%d\n", count + extra);
    return 0;
}
/*此题 不晓得该表达些啥 就一个字叼
主要意思为 给你一个字符串 判断如果能还原为回文串要移动多少次(只能相邻移动)
可以利用回文串的性质 因为左右对称 所以用两个嵌套for循环 外层循环变量i表示要比对的字符的比对对象 
内层循环变量j 表示比对的字符 如果i ！= j 时 比对到字符相等的 证明可以匹配 把j移动到end位置上 因为i表示左半部分 end表示
右半部分 因为是回文串 所以i与end 是对应的 如 i为0 end为n-1 对称的 匹配完后 end-- 匹配倒数第二个

但此题目骚就骚在如果字符串长度为奇数 有一个字符没有匹配 那么应该将其放在中间 应该在if(i == j)中执行
但不能这样操作 反例ffdejjell 在操作的时候 第一次会把d放中间 但接下来会有一次非 i == j的情况移动 会把d再次移动到
非中间的位置这样根据判断 会直接impoosible 并且如果非要移动 的话 实验了一波 但会使总次数增加
所以正确的操作方法是不移动(也不能说是不移动 是放在最后移动 但最后已经不需要移动了)，只需记录不能匹配字符的当前位置与中间的距离
虽然这样使得i与end不在形式上对称了 但本质上依然对称
此题还特么是个贪心  
*/
