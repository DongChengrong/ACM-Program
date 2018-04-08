#include<stdio.h>
#include<string.h>

#define N 100 + 20

int a[N][N],v[N][N];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int i,j,k;
        char c;
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                while((c = getchar()) == '\n');
                a[i][j] = (c == 'x' ? 0 : 1);
            }
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                for(k = 0; k < 4; k++)
                    v[i][j] += a[i+dir[k][0]][j+dir[k][1]];
        int ok = 1;
        for(i = 1; i <= n; i++)
            for(j = 0; j <= n; j++)
                if(v[i][j] % 2) ok = 0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
