#include<stdio.h>

int count(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(n & 1) return count(n - 1) + 1;
    else return count(n / 2) + 1;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",count(n));
    }
    return 0;
}
