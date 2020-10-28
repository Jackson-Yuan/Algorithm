//±©Á¦ 
/*#include<stdio.h>
#include<string.h>
using namespace std;
char a[100];
char b[100];
int changed[100];
int n;
int count;
void dfs(int index){
	if(index == n){
		memset(changed, 0, sizeof(changed));
		for(int i = 0 ; i < n ; i++){
			if(i == 0){
				if((a[i] == 'B' && a[n - 1] == 'A') || (a[i] == 'A' && a[i + 1] == 'B')) changed[i] = 1;
			}else if(i == n - 1){
				if((a[i] == 'B' && a[i - 1] == 'A') || (a[i] == 'A' && a[0] == 'B')) changed[i] = 1;
			}else{
				if((a[i] == 'B' && a[i - 1] == 'A') || (a[i] == 'A' && a[i + 1] == 'B')) changed[i] = 1;
			}
		}
		
		int flag = 0;
		for(int i = 0 ; i < n ; i++){
		     if(changed[i] != 1 && a[i] != b[i]){
		     	flag = 1;
		     	break;
		     }else if(changed[i] == 1 && a[i] == b[i]){
		     	flag = 1;
		     	break;
			 }
		}
		if(!flag) count++;
		return;
	}
	a[index] = 'A';
	dfs(index + 1);
	a[index] = 'B';
	dfs(index + 1);
}
int main(){
	scanf("%s",b);
    n = strlen(b);
	dfs(0);
	printf("%d\n",count);
}*/
