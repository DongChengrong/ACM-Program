#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += (n - i) * i + 1;
        printf("%d\n",ans);
    }
    return 0;
}
