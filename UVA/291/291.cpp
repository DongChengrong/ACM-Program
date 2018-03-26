#include<stdio.h>
#include<string.h>

const int maxn = 5 + 10;
int map[maxn][maxn];
char s[maxn];

void make_map()
{
    memset(map,0,sizeof(map));
    for(int i = 1; i <= 5; i++)
        map[i][i] = 1;
    map[1][4] = map[4][1] = 1;
    map[2][4] = map[4][2] = 1;
}

void dfs(int x, int k)
{
    s[k] = (x + '0');
    if(k == 9)
    {
        s[k+1] = '\0';
        printf("%s\n",s+1);
    }
    for(int i = 1; i <= 5; i++)
    {
        if(!map[x][i])
        {
            map[x][i] = map[i][x] = 1;
            dfs(i,k+1);
            map[x][i] = map[i][x] = 0;
        }
    }
}

int main()
{
    make_map();
    dfs(1,1);
    return 0;
}
