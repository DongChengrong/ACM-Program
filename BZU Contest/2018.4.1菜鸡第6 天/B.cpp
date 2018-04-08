
#include<stdio.h>

#define N 101000

int t[N];

int main(){
    int n;
    while(scanf("%d",&n) == 1){
        for(int i = 1; i <= n; i++)
            scanf("%d",&t[i]);
        int a = 0,b = 1;
        int i = 1,j = n;
        int pa = 0,pb = 0;
        while(i <= j){
            while(a < b && i <= j){
                a += t[i++];
                pa++;
            }
            while(a >= b && i <= j){
                b += t[j--];
                pb++;
            }
        }
        printf("%d %d\n",pa,pb);
    }
	return 0;
}