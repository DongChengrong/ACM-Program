#include<stdio.h>
#include<vector>
using namespace std;

#define N 110

int n,m;
vector<int> G[N];
int vis[N];

void dfs(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(vis[j]) continue;
        for(int k = 0; k < G[i].size(); k++)
        {
            if(vis[j]) break;
            for(int z = 0; z < G[j].size(); z++)
            if(G[i][k] == G[j][z]) { vis[j] = 1; dfs(j); break;}
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        //init
        for(int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            G[i].clear();
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++)    //create Gragh
        {
            int k;
            scanf("%d",&k);
            if(k == 0) cnt++;
            for(int j = 0; j < k; j++)
            {
                int x;
                scanf("%d",&x);
                G[i].push_back(x);
            }
        }

        if(cnt == n) { printf("%d\n",n); continue; }

        int ans = -1;
        for(int i = 1; i <= n; i++)
        if(!vis[i]) { vis[i] = 1; ans++; dfs(i); }

        printf("%d\n",ans);
    }
    return 0;
}
