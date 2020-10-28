#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;
struct node {
    int length;
    int weight;
};

bool compare(struct node a, struct node b) {
    if (a.weight == b.weight) return a.length < b.length;
    else return a.weight < b.weight;
}

int visited[5000];
struct node a[5000];

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        int count = 0;
        scanf("%d", &n);
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].length, &a[i].weight);
        }
        sort(a, a + n, compare);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            count++;
            int tempLength = a[i].length;
            int tempWeight = a[i].weight;
            for (int j = i + 1; j < n; j++) {
                if (visited[j] == 1) continue;
                if (a[j].weight >= tempWeight && a[j].length >= tempLength) {
                    visited[j] = 1;
                    tempLength = a[j].length;
                    tempWeight = a[j].weight;
                }
            }
        }
        printf("%d\n", count);
    }
}
/*
���� ̰��ûɶ��˵�� 
�������Ϊ ����Ŀ������i+1��ľ��������ȣ����������ڵ��ڵ�i��ľ�� ��ô��i+1��ľ���򲻺ķ�ʱ��  
������Ҫ���� ��֯һ������ ΪʲôҪ���� ���ɺܼ� �����Ŀ����˼·��ѡȡһ��ľ�� ����ʣ���ľ�� �����ж��ٸ�ľ���ܸ�ѡ����ľ�����һ�� 
�����ٴ�ʣ��û�����ѡ��һ��ľ�� �ػظ��ղŵĲ��� ֪���������� ��ô�ж������� �ͺķѶ���ʱ�� 
��������� ��ôÿ�������ľ���ĸ����Ͳ����ܾ����ܵĶ� �����ԭ�� ���԰�weight�� Ҳ���԰�length�� ������ֵû�й�ϵ ��ȫ��� �������ߵ�λ�ȼ� �����ĸ��Ž����һ�� 
*/
