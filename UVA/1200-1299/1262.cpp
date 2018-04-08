#include<stdio.h>
#include<string.h>

char p[2][10][10];
int k,cnt;
char s[10];

int dfs(int col)
{
    if(col == 5)
    {
        if((++cnt) == k)
        {
            s[5] = '\0';
            printf("%s\n",s);
            return 1;
        }
        else
            return 0;
    }

    int vis[2][30];
    memset(vis, 0 ,sizeof(vis));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 6; j++)
            vis[i][p[i][j][col] - 'A'] = 1;

    for(int i = 0; i < 26; i++)
    {
        if(vis[0][i] && vis[1][i])
        {
            s[col] = 'A' + i;
            if(dfs(col + 1)) return 1;
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 6; j++)
                scanf("%s",p[i][j]);

        cnt = 0;
        if(!dfs(0)) printf("NO\n");
    }
    return 0;
}
