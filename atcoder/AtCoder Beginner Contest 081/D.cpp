#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define FOR(a,n) for(int i = a; i <= n; i++)

const int maxn = 1000 + 10;
int a[maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);

        int MAX = 1;
        for(int i = 1; i <= n; i++)
            if(abs(a[i]) > abs(a[MAX])) MAX = i;

        if(a[MAX] == 0)
        {
            printf("0\n");
            continue;
        }

        printf("%d\n",2 * n);

        if(a[MAX] > 0)
        {

            FOR(1,2)
                printf("%d %d\n",MAX,n);

            FOR(1,n-1)
            {
                printf("%d %d\n",n,i);
                printf("%d %d\n",n,n);
            }
        }
        else
        {
            FOR(1,2)
                printf("%d %d\n",MAX,1);

            for(int i = n; i > 1; i--)
            {
                printf("%d %d\n",1,i);
                printf("%d %d\n",1,1);
            }
        }
    }
    return 0;
}
