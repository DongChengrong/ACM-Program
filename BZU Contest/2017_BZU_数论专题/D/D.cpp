#include<stdio.h>

int is(int n)
{
    int x = n;
    int a1,a2,a3;
    a1 = x % 10; x /= 10;
    a2 = x % 10; x /= 10;
    a3 = x % 10;
    return a1 * a1 * a1 + a2 * a2 * a2 + a3 * a3 *a3 == n;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        int flag = 0;
        for(int i = n; i <= m; i++)
        {
            if(is(i))
            {
                if(flag) printf(" ");
                printf("%d",i);
                flag = 1;
            }
        }
        if(!flag) printf("no\n");
        else printf("\n");
    }
    return 0;
}
