#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 20;
const int INF = 10000000;
int n;
int a[maxn][maxn],b[maxn][maxn];

int check(int s)
{
    memset(b,0,sizeof(b));
    //枚举第一行
    for(int i = 0; i < n; i++)
    {
        if(s & (1 << i)) b[0][i] = 1;
        else if(a[0][i]) return INF;
    }

    //根据第一行计算剩下的几行
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            int sum = 0;
            if(r > 0) sum += b[r - 1][c];
            if(c > 0) sum += b[r][c-1];
            if(c < n - 1) sum += b[r][c+1];
            b[r+1][c] = sum % 2;
            if(b[r][c] == 0 && a[r][c] == 1)
                return INF;
        }
    }

    //计算改变的个数
    int cnt = 0;
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
            if(a[r][c] != b[r][c])
                cnt++;

    return cnt;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d",&a[i][j]);

        int ans = INF;
        for(int i = 0; i < (1 << n); i++)
            ans = min(check(i),ans);
        printf("Case %d: %d\n",kase,ans == INF ? -1 : ans);
    }
    return 0;
}
