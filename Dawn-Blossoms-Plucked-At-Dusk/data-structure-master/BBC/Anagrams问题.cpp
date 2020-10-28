#include<stdio.h>
#include<string.h>

using namespace std;
char a[1000];
char b[1000];
int visited[1000];

int main() {
    scanf("%s", a);
    int suma = strlen(a);
    for (int i = 0; i < suma; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] + 32;
        }
    }
    scanf("%s", b);
    int sumb = strlen(b);
    for (int i = 0; i < sumb; i++) {
        if (b[i] >= 'A' && b[i] <= 'Z') {
            b[i] = b[i] + 32;
        }
    }

    if (suma != sumb) {
        printf("N\n");
    } else {
        int flag;
        for (int i = 0; i < suma; i++) {
            flag = 0;
            for (int j = 0; j < sumb; j++) {
                if (b[j] == a[i] && visited[j] == 0) {
                    visited[j] = 1;
                    flag = 1;
                    break;
                }
            }
            if (!flag) break;
        }

        if (!flag) printf("N\n");
        else printf("Y\n");
    }
}
