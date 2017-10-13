#include<stdio.h>

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n % (m + 1) == 0) printf("Lose\n");
        else printf("Win\n");
    }
    return 0;
}
