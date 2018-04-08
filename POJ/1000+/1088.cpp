#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
const int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int r,c;
int d[maxn][maxn],a[maxn][maxn];

int dp(int i,int j)
{
    if(d[i][j] != 0) return d[i][j];

    int ans = 1;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if(x < 0 || x >= r || y < 0 || y >= c) continue;
        if(a[x][y] < a[i][j])
        {
            ans = max(ans,1 + dp(x,y));
        }
    }
    return d[i][j] = ans;
}

int main()
{
    while(scanf("%d%d",&r,&c) == 2)
    {
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d",&a[i][j]);

        int ans = 0;
        memset(d,0,sizeof(d));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                ans = max(ans,dp(i,j));

        printf("%d\n",ans);
    }
    return 0;
}
