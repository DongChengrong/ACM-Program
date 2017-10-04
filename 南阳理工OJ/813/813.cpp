#include<stdio.h>

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2 && n && k)
    {
        int ok = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i * (n - i) == k)
            {
                ok = 1;
                break;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
