#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100+5;

int m,n;
int id[maxn][maxn];
char oil[maxn][maxn];

void dfs(int i,int j)
{
    if(i<0 || i>=m || j<0 || j>=n) return;
    if(id[i][j]) return;
    if(oil[i][j]=='*') return;
    id[i][j]=1;#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100+5;

int m,n;
int id[maxn][maxn];
char oil[maxn][maxn];

void dfs(int i,int j)
{
    if(i<0 || i>=m || j<0 || j>=n) return;
    if(id[i][j]) return;
    if(oil[i][j]=='*') return;
    id[i][j]=1;
    for(int k=-1;k<=1;k++)
        for(int z=-1;z<=1;z++)
            if(k!=0 || z!=0) dfs(i+k,j+z);
}

int main()#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100+5;

int m,n;
int id[maxn][maxn];
char oil[maxn][maxn];

void dfs(int i,int j)
{
    if(i<0 || i>=m || j<0 || j>=n) return;
    if(id[i][j]) return;
    if(oil[i][j]=='*') return;
    id[i][j]=1;
    for(int k=-1;k<=1;k++)
        for(int z=-1;z<=1;z++)
            if(k!=0 || z!=0) dfs(i+k,j+z);
}

int main()
{
    while(scanf("%d%d",&m,&n)==2 && m)
    {
        int ans=0;
        memset(id,0,sizeof(id));
        for(int i=0;i<m;i++) scanf("%s",oil[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(!id[i][j] && oil[i][j]=='@') { dfs(i,j); ans++; }
            }
        printf("%d\n",ans);
    }
    return 0;
}
{
    while(scanf("%d%d",&m,&n)==2 && m)
    {
        int ans=0;
        memset(id,0,sizeof(id));
        for(int i=0;i<m;i++) scanf("%s",oil[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(!id[i][j] && oil[i][j]=='@') { dfs(i,j); ans++; }
            }
        printf("%d\n",ans);
    }
    return 0;
}
    for(int k=-1;k<=1;k++)
        for(int z=-1;z<=1;z++)
            if(k!=0 || z!=0) dfs(i+k,j+z);
}

int main()
{
    while(scanf("%d%d",&m,&n)==2 && m)
    {
        int ans=0;
        memset(id,0,sizeof(id));
        for(int i=0;i<m;i++) scanf("%s",oil[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(!id[i][j] && oil[i][j]=='@') { dfs(i,j); ans++; }
            }
        printf("%d\n",ans);
    }
    return 0;
}
