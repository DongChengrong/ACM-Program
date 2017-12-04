#include<stdio.h>

int main()
{
    int n,m,T;
    scanf("%d",&T);
    while(T--)
    {
        int count = 0;
        scanf("%d%d",&n,&m);
        while(m <= n)
        {
            count += n / m;
            n /= m;
        }
        printf("%d\n",count);
    }
    return 0;
}
