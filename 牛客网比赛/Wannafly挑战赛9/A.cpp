#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long LL;

const int maxn = 1000000 + 20;
int a[maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }

        int num = 0;
        if(a[1]) num += a[1];
        for(int i = 2; i <= 1000000; i++)
        {
            for(int j = 2 * i; j <= 1000000; j += i)
            {
                if(a[j])
                {
                    num += a[i]; break;
                }
            }
        }

        printf("%d\n",num);
    }
    return 0;
}
