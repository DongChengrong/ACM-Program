#include<stdio.h>

#define N 110

int n;
int a[N];

bool s,c;

int dfs(int i){
    if(i == n) return 0;

    if(a[i] == 0) return 1 + dfs(i + 1);
    if(a[i] == 1){
        if(!c) {
            c = true;
            return dfs(i+1);
        }else{

        }
    }
}

int main()
{
    while(scnaf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scnaf("%d",&a[i]);

        s = c = false;
        printf("%d\n",dfs(0))
    }
    return 0;
}
