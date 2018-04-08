#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int maxn = 200 + 10;
int cnt;
int d[maxn][2],f[maxn][2];

map<string, int> dict;
vector<int> sons[maxn];

void init(int n)
{
    dict.clear();
    cnt = 0;
    for(int i = 0; i < n; i++)
        sons[i].clear();
}

int ID(string s)
{
    if(dict.count(s) == 0) dict[s] = cnt++;
    return dict[s];
}

int dp(int u,int k)
{
    d[u][k] = k;
    f[u][k] = 1;
    for(int i = 0; i < sons[u].size(); i++)
    {
        int v = sons[u][i];
        if(k == 1)
        {
            d[u][k] += dp(v, 0);
            if(!f[v][0]) f[u][k] = 0;
        }
        else
        {
            d[u][k] += max(dp(v, 0), dp(v, 1));
            if(d[v][0] == d[v][1]) f[u][k] = 0;
            else if(d[v][0] > d[v][1] && !f[v][0]) f[u][k] = 0;
            else if(d[v][0] < d[v][1] && !f[v][1]) f[u][k] = 0;
        }
    }
    return d[u][k];
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    string s, s2;
    while(cin >> n && n)
    {
        init(n);
        cin >> s;
        ID(s);
        for(int i = 0; i < n - 1; i++)
        {
            cin >> s >> s2;
            sons[ID(s2)].push_back(ID(s));
        }

        int ok = 0;
        cout << max(dp(0, 0), dp(0, 1)) <<" ";
        if(d[0][1] > d[0][0] && f[0][1]) ok = 1;
        if(d[0][0] > d[0][1] && f[0][0]) ok = 1;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
