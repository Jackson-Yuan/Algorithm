#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<algorithm>
#include<math.h>

using namespace std;

void put(int num, int n) {//numΪ��ǰ����nΪ���η�
    //printf("num = %d, n = %d\n",num,n);
    if (num == 0)return;//�����������ֽ����
    int r = num % 2;//���һλȡ����
    num = num >> 1;//����һλ
    put(num, n + 1);//��һλ�η� +1
    if (num && r)printf("+");//ǰ��͵�ǰλ��0��ʱ�����'+'��
    if (r) {//��ǰ���һλ ��0 ��ô�����Ӧ�ı�ʾ
        if (n == 1)
            printf("2");
        else {
            printf("2(");
            if (n == 0)printf("0");
            else put(n, 0);//�η����ڵ���2 ʱ�������ֽ�
            printf(")");
        }
    }
}

int main() {
    int num;
    scanf("%d", &num);
    put(num, 0);//�տ�ʼ ���һλ ��0�η�
    return 0;
}
/**
�ݹ���Ŀ ��
��������̫�� ��Ŀ��˼���ǽ�һ��ʮ������ ת��Ϊ������ ͬʱֻ����2^1 �� 2^0��ʾ �ݹ�ɽ�� ����Ҫ���� 
*/
