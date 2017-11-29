/*
*作者：董成荣
*创建时间：2017/11/25
*题目描述：一道简单的DP问题
*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
const int INF = 10000000;
int n,e;   //n代表节点数，e代表边数
int a[maxn][maxn],d[maxn][maxn];
vector<int> G[maxn];

int dp(int i, int j)
{
    if(d[i][j] != 0) return d[i][j];
    if(j == n) return d[i][j] = a[i][j];

    int ans = INF;
    for(int k = 0; k < G[j].size(); k++)
        ans = min(ans, dp(j,G[j][k]) + a[i][j] );

    return d[i][j] = ans;
}

int main()
{
    while(scanf("%d%d",&n,&e) == 2)
    {
        //init
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        for(int i = 0; i < n; i++)
            G[i].clear();

        for(int i = 0; i < e; i++)
        {
            int u,v,w;   //代表从u到v的有向边权值为w
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(v);
            a[u][v] = w;
        }

        //寻找最优解
        int result = INF;
        for(int i = 0; i < G[1].size(); i++)
            result = min(result,dp(1,G[1][i]));

        printf("%d\n",result);
    }
    return 0;
}
/*
*test data
*测试数据
10 14
1 2 4
1 3 2
2 4 1
2 5 5
3 4 3
3 5 4
3 6 3
5 7 6
5 8 5
6 8 5
7 10 3
8 10 4
9 10 6
4 9 6
*/
