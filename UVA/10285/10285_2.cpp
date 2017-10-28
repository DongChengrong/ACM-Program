#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int dir[2][4] = {{1,0,-1,0},{0,1,0,-1}};
const int maxn = 100 + 10;
int M[maxn][maxn],d[maxn][maxn],R,C;
char s[maxn];

int dp(int i, int j)
{
    if(d[i][j] != 0) return d[i][j];

    int &ans = d[i][j];

    for(int k = 0; k < 4; k++)
    {
        int x = i + dir[0][k];
        int y = j + dir[1][k];

        if(x < R && y < C && x >= 0 && y >= 0 && M[x][y] < M[i][j])
            ans = max(ans, dp(x,y));
    }

    return ans += 1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s %d %d",s,&R,&C);

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                scanf("%d",&M[i][j]);

        int ans = 0;

        memset(d,0,sizeof(d));

        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                ans = max(ans, dp(i,j));

        printf("%s: %d\n",s,ans);
    }
    return 0;
}
