#include<stdio.h>
#include<string.h>

#define N 3300

int a[N];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int cost = 0;
        memset(a,0,sizeof(a));
        while(n--)
        {
            int x,i = 0;
            scanf("%d",&x);
            while(1)
            {
                if(a[x + i] == 0) break;
                i++;
            }
            cost += i;
            a[x + i] = 1;
        }
        printf("%d\n",cost);
    }
    return 0;
}
