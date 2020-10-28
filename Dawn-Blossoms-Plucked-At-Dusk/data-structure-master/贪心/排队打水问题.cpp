/**
n����ȥr��ˮ��ͷ��ˮ��װˮ��ʱ��Ϊt1��tn��Ӧ��ΰ������ǵ�˳�� ʹ��ÿ����ʵ�ʴ�ˮʱ���ܺ���С 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int n, r;
int perTime[500];
int wait[500];

int main() {
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> perTime[i];
    }

    for (int i = 0; i < r; i++) {
        wait[i] = 0;
    }

    sort(perTime, perTime + n);
    for (int i = 0; i < n; i++) {
        int temp = perTime[i];
        int index = i % r;
        perTime[i] += wait[index];
        wait[index] += temp;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += perTime[i];
    }

    cout << sum << endl;
}
/**
��������̰��
��ΪҪʹʵ�ʴ�ˮʱ����С ʵ�ʴ�ˮʱ��Ϊ��ˮʱ�� �ȴ�ʱ��֮�� ��ˮʱ��̶��޷��ı䣬���Ծ�����ʹ�ȴ�ʱ����С
����Ӧ��ʹ��ˮʱ�����ٵ�����ȥ�� ���� ��Сʱ�� = ��ˮʱ��֮�� + �ȴ�ʱ��(�ɽ�ˮʱ�����) 
����r��ˮ��ͷ Ҫ��ǰr��ˮʱ��С����ȥ�� ������һ��r�� ����ÿһ����ÿ������ǰһ����ÿ������û�б�Ȼ��Ӧ��ϵ ��д�����ʱ��ֻ��ǿ�м���һ�ֶ�Ӧ��ϵ ��Ȼû���㰡  
*/

