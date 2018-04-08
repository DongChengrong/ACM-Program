/*
当前节点的值首先不能与父节点的颜色相同
其次不能与祖父节点的值相同
最后，不能与父节点的其他子节点值相同
从一个根节点出发向下找
*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define N 210000

vector<int> G[N];
int pa[N], col[N];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {

        memset(pa,0,sizeof(pa));
        memset(col,0,sizeof(col));
        for(int i = 1; i <= n; i++)
            G[i].clear();

        for(int i = 0; i < n - 1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int res = 1;
        pa[1] = 1; col[1] = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            int num = 1;

            for(int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                if(!col[v])
                {
                    if(col[u] == num || col[pa[u]] == num) num++;
                    if(col[u] == num || col[pa[u]] == num) num++;

                    res = max(res, num);
                    pa[v] = u;
                    col[v] = num++;
                    q.push(v);
                }
            }
        }

        printf("%d\n",res);
        for(int i = 1; i <= n; i++)
            printf("%d%c",col[i], i == n ? '\n' : ' ');
    }
    return 0;
}
