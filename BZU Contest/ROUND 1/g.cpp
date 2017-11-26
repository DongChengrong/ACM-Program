#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int cmp(int a,int b)
{
    return abs(a) > abs(b);
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        printf("%d",a[0]);
        for(int i = 1; i < n; i++)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
