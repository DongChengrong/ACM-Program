#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n) == 2)
    {
        int ans = (m - 1) * n + (n - 1);
        printf("%d\n",ans);
    }
    return 0;
}
