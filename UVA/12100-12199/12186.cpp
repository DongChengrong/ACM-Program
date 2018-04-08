#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100000;
vector<int> v[maxn];
int n,t,x;

int dp(int u)
{
    if(v[u].empty()) return 1;
    int k=v[u].size();
    int m=(k*t-1)/100+1;
    vector<int> d;
    for(int i=0;i<k;i++) d.push_back(dp(v[u][i]));
    int ans=0;
    sort(d.begin(),d.end());
    for(int i=0;i<m;i++) { ans+=d[i]; }
    return ans;
}

void clear()
{
    for(int i=0;i<=n;i++)
    {
        while(!v[i].empty()) v[i].pop_back();
    }
}

int main()
{
    while(scanf("%d %d",&n,&t)==2 && (n&&t))
    {
        clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            v[x].push_back(i);
        }
        printf("%d\n",dp(0));
    }
    return 0;
}
