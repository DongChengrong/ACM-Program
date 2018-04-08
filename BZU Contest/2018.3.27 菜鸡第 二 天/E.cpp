#include<stdio.h>

int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m) == 2)
    {
        int i;
        printf("%d\n",m + n - 1);
        for(i = 1; i <= m; i++)
            printf("%d %d\n",1,i);
        for(i = 2; i <= n; i++)
            printf("%d %d\n",i,m);
    }
    return 0;
}
