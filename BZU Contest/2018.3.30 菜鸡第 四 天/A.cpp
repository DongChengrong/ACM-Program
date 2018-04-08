#include<stdio.h>
#include<algorithm>
using namespace std;

#define N 110

int a[N];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        int MIN = 0x3f3f3f3f;
        int MIN1 = 0;
        for(int i  = 2; i <= n; i++)
            MIN1 = max(MIN1, a[i] - a[i-1]);
        for(int i  = 3; i <= n; i++)
            MIN = min(MIN, a[i] - a[i-2]);
        printf("%d\n",max(MIN,MIN1));
    }
    return 0;
}
