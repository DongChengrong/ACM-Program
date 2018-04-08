#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 1000000;
const int maxm = 10 + 5;
const int maxn = 100 + 10;
int a[maxm][maxn],d[maxm][maxn];
int nxt[maxm][maxn];

int main()
{
    int n,m;
    while(scanf("%d %d",&m,&n) == 2)
    {
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++)
                scanf("%d",&a[i][j]);

        int ans = INF,first = 0;
        for(int j = n;j >= 1;j--)
        {
            for(int i = 1;i <= m;i++)
            {
                if(j == n) d[i][j] = a[i][j];
                else
                {
                    int rows[3] = {i,i-1,i+1};
                    if(i == 1) rows[1] = m;
                    if(i == m) rows[2] = 1;
                    sort(rows,rows+3);
                    d[i][j] = INF;
                    for(int k = 0;k < 3;k++)
                    {
                        int v = a[i][j] + d[rows[k]][j+1];
                        if(v < d[i][j])
                        {
                            d[i][j] = v;
                            nxt[i][j] = rows[k];
                        }
                    }
                }
                if(j == 1 && d[i][j] < ans)
                {
                    ans = d[i][j];
                    first = i;
                }
            }
        }

        printf("%d",first);
        for(int i = nxt[first][1],j = 2;j <= n;i = nxt[i][j],j++)
            printf(" %d",i);
        printf("\n%d\n",ans);
    }
    return 0;
}
