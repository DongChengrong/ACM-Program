#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int cost = 0;
        int x,p = 0;
        while(n--)
        {
            scanf("%d",&x);
            if(p > x) cost += (p - x) * 4 + 5;
            else cost += (x - p) * 6 + 5;
            p = x;
        }
        printf("%d\n",cost);
    }
    return 0;
}
