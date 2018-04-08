#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
char s[50];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
int a[maxn][maxn],d[maxn][maxn];
int r,c;

int dp(int i, int j)
{
    if(d[i][j] != -1) return d[i][j];
    int ans = 1;
    for(int k = 0; k < 4; k++)
    {
        int x = dx[k] + j;
        int y = dy[k] + i;
        if(x >= 0 && x < c && y >= 0 && y < r && a[y][x] < a[i][j])
            ans = max(ans, dp(y,x) + 1);
    }
    return d[i][j] = ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%d%d",s,&r,&c);

        //Â¼ÈëÊý¾Ý
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d",&a[i][j]);

        memset(d, -1, sizeof(d));

        int ma = 1;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
            {
                int v = dp(i,j);
                if(v > ma) ma = v;
            }
        printf("%s: %d\n",s,ma);
    }
    return 0;
}
