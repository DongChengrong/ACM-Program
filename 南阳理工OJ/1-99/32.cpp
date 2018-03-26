#include<stdio.h>

int m, n;

void dfs(int *a, int cnt)
{
    if(cnt == n) {
        for(int i = 1; i <= n; i++)
            printf("%d",a[i]);
        printf("\n");
    }
    for(int j = a[cnt] - 1; j >= 1; j--)
    {
        a[cnt+1] = j; dfs(a,cnt+1);
    }
}

int main()
{
    while(scanf("%d%d",&m,&n) == 2)
    {
        int a[100];
        for(int i = m; i >= 1; i--)
        {
            a[1] = i;
            dfs(a,1);
        }
    }
    return 0;
}
