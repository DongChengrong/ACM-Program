#include<stdio.h>

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        if(n <= k) printf("2\n");
        else printf("%d\n",(n * 2 - 1) / k + 1);
    }
    return 0;
}
