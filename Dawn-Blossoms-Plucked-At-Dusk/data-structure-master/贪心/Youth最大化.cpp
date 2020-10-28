#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
double v[10005];
double w[10005];
double s[10005];
int n, k;

bool judge(double value) {
    for (int i = 0; i < n; i++) {
        s[i] = v[i] - value * w[i];
    }
    sort(s, s + n);
    double sum = 0;
    int index = n - 1;
    int count = k;
    while (count--) {
        sum += s[index];
        index--;
    }
    if (sum >= 0) return true;
    else return false;
}

void search(double left, double right) {
    while (right > left + 0.0000001) {
        double mid = (left + right) / 2;
        if (judge(mid)) left = mid;
        else right = mid;
    }
    printf("%.2lf\n", left);
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        double max = -1;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &w[i], &v[i]);
            double temp = v[i] / w[i];
            if (temp > max) max = temp;
        }
        search(0, max);
    }
}
/*
���ⲻ�ܰ����뵱Ȼ �����Լ۱ȴӴ�С��һ�£�ȡǰk�� 
���� 10 5  20 11   20 60
������˼· ��ʵ��Ȧ������Լ۱ȵķ�Χ ���ö��ֲ��� �ж�
�ж����� Ҳ�н��� ��v[i]/w[i]>=x �� v[i] - x * w[i]>=0
���жϵ��Լ۱ȴ���judge���� ��ÿ����Ʒ����Լ۱ȱȽ� ����
ȡ����ǰk�� ���Ƿ�ʹ���0 �����ڵ���0 ���� ǰk������������ڴ��Լ۱� ���Լ����Ŵ� ��left��ֵΪmid
С��0 ��right��ֵΪmid ���ж���ѭ���жϵ�����������left<right ���� right - left > 0.00000001 ��Ϊ�Ǹ�����
 ������left �� right ����������ѭ���� �Ͳ��ò�ֵ����0.0000001��������(���Ű�) 
*/ 
