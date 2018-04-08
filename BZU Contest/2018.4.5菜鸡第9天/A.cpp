#include<stdio.h>
#include<string.h>

#define N 110

int m,n;
int vis[N][N],a[N][N];

void init()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            vis[i][j] = 1;
}

void fill_col(int j)
{
    for(int i = 1; i <= m; i++)
        vis[i][j] = 0;
}

void fill_row(int i)
{
    for(int j = 1; j <= n; j++)
        vis[i][j] = 0;
}

bool check(int r, int c)
{
    int cnt = 0;
    for(int i = 1; i <= m; i++)
        if(vis[i][c] == 1) cnt++;
    for(int i = 1; i <= n; i++)
        if(vis[r][i] == 1) cnt++;
    if(cnt >= 1) return true;
    return false;
}

int main()
{
    while(scanf("%d%d",&m,&n) == 2)
    {
        init();
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&a[i][j]);
                if(!a[i][j])
                {
                    fill_row(i);
                    fill_col(j);
                }
            }

        bool ok = true;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(!ok) break;
                if(a[i][j] && !check(i,j)) ok = false;
            }

        if(ok)
        {
            printf("YES\n");
            for(int i = 1; i <= m; i++)
                for(int j = 1; j <= n; j++)
                    printf("%d%c",vis[i][j],j == n ? '\n' : ' ');
        }
        else printf("NO\n");
    }
    return 0;
}
