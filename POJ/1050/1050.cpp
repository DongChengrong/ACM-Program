#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int m[maxn][maxn];
int temp[maxn];

int getResult(int n)
{
    int Max = -10000000,ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(ans < 0) ans = temp[i];
        else ans += temp[i];
        Max = max(ans,Max);
    }
    return Max;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&m[i][j]);

        int ans = -100000000;
        for(int i = 0; i < n; i++)
        {
            memset(temp,0,sizeof(temp));
            for(int j = i; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                    temp[k] += m[j][k];
                ans = max(ans,getResult(n));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
