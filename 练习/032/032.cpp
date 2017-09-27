#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n & 1) printf("%d 是奇数\n",n);
        else printf("%d 是偶数\n",n);
    }
}
