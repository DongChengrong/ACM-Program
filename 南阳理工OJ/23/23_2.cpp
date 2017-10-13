#include<stdio.h>

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%s\n",n % (m + 1) == 0 ? "Lose":"Win");
    }
    return 0;
}
