#include<stdio.h>

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(n%m==0) printf("%d\n",n/m);
        else printf("%d\n",n/m+1);
    }
    return 0;
}
