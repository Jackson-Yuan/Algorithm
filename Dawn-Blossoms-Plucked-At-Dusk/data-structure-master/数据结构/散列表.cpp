#include<stdio.h>
/**
字符串散列表 
*/

/**
仅限大写字符
A~Z 看成0~25 看成26进制 根据进制转换结论 不同字符串 结果唯一
若混合大小写字母 则可以看出52 进制 
*/
int stringHash(char *str, int length) {
    int id = 0;
    int temp = 1;
    for (int i = length - 1; i >= 0; i--) {
        id += (str[i] - 'A') * temp;
        temp *= 26;
    }

    return id;
}

int stringHash2(char *str, int length) {
    int id = 0;
    for (int i = 0; i < length; i++) {
        id = id * 26 + (str[i] - 'A');
    }

    return id;
}

/**
大小写混合
如果再加入数字0~9 就扩成62进制 
*/
int stringHash3(char *str, int length) {
    int id = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            id = id * 52 + (str[i] - 'A');
        } else {
            id = id * 52 + (str[i] - 'A') + 26;
        }
    }

    return id;
}

int main() {
    char *str = "ABDx";
    printf("%d\n", stringHash3(str, 8));
}
