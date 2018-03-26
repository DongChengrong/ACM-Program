#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 26 + 5;

char old[maxn],now[maxn];
int a[maxn];
int vis[maxn],has[maxn];
vector<int> l[maxn];
int cnt;

void init()
{
    cnt = 0;
    memset(vis,0,sizeof(vis));
    memset(has,0,sizeof(has));
}

void dfs(int i)
{
    vector<int> v = l[i];
    for(int j = 0; j < v.size(); j++)
    {
        if(has[v[j]] && !vis[v[j]])
            dfs(v[j]);
    }
    vis[i] = 1;
    a[cnt++] = i;
}

int main()
{
    init();
    scanf("%s",old);
    while(scanf("%s",now) && now[0] != '#')
    {
        int len = min(strlen(now),strlen(old));
        for(int i = 0; i < len; i++)
        {
            if(old[i] != now[i])
            {
                int p1 = old[i] - 'A', p2 = now[i] - 'A';
                has[p1] = has[p2] = 1;
                l[p1].push_back(p2);
                break;
            }
        }
        memcpy(old,now,sizeof(now));
    }
    for(int i = 0; i < 26; i++)
        if(has[i] && !vis[i])
            dfs(i);
    for(int i = cnt - 1; i >= 0; i--)
        putchar(a[i] + 'A');
    putchar('\n');
    return 0;
}
