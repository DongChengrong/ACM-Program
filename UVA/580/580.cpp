#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int ans = pow(2,n-3) * (n - 2) - (n - 3) - (n - 4)*(pow(2,n-3) - 2);
        printf("%d\n",ans);
    }
    return 0;
}
