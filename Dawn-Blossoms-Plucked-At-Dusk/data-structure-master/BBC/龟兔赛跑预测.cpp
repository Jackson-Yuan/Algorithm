#include<stdio.h>

int main() {
    int v1, v2;
    int t, s, l;
    scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
    int tortiseTime = l / v2;
    int rabbitTime = 0;
    int tortiseDistance = 0;
    int rabbitDistance = 0;
    for (int i = 1; i <= tortiseTime; i++) {
        /*��Ϊ��ǰ���� �ڼӾ���֮ǰ ���ж�һ������� С���趨ֵ ���߶��� ����ֻ���ڹ�*/
        if (rabbitDistance - tortiseDistance < t) {
            rabbitDistance += v1;
            tortiseDistance += v2;
        } else {
            /*ֻ���ڹ�ʱע�� Ҫ�ӵ�������Ϣ�꿪ʼ��һ���жϾ���ʱ������start(��Ϣʱ���жϾ����) ͬʱ����ѭ�� ������ ����Ҫ��ȥ1*/
            int start = i + s;
            int temp = i;
            i = start - 1;
            /*�ڹ���Ҫ�ӵľ��� �Ǿ���������i �봦��ǰ�ĵĲ�+1*/
            tortiseDistance += (i - temp + 1) * v2;
        }
        /*���������ĵ�ʱ�� ���ǵ�ǰiֵ*/
        rabbitTime = i;
        /*�����ݼ���� �����Ӿ����Ѿ����ڵ�����󳤶� ��ֱ�ӽ���ѭ�� ��Ϊѭ�����������ֵΪ�ڹ�ʱ�� �����ǰ���� ˵�������Ѿ���ǰ�����յ�*/
        if (rabbitDistance >= l) break;
    }
    if (tortiseDistance > rabbitDistance) {
        printf("T\n");
        printf("%d\n", tortiseTime);
    } else if (tortiseDistance < rabbitDistance) {
        printf("R\n");
        printf("%d\n", rabbitTime);
    } else {
        printf("D\n");
        printf("%d\n", tortiseTime);
    }
}
/*
����˼· �����Դ���ˬ ����ʵ�������Ƶ�������� ������ ���ż� ��ס 
*/
