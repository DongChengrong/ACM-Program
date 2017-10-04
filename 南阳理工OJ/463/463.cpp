#include<stdio.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= 9; j++)
                printf("%d*%d=%d ",i,j,i * j);
            printf("\n");
        }
        if(T) printf("\n");
    }
    return 0;
}
