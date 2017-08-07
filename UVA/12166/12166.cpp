#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int sum;
string s;
map<long long,int> m;

void dfs(int depth,int b,int e)
{
    if(s[b]=='[')
    {
        int p=0;
        for(int i=b+1;i<e;i++)
        {
            if(s[i]=='[') p++;
            if(s[i]==']') p--;
            if(p==0 && s[i]==',')
            {
                dfs(depth+1,b+1,i-1);
                dfs(depth+1,i+1,e-1);
            }
        }
    }
    else
    {
        long long w=0;
        sum++;
        for(int i=b;i<=e;i++) w=w*10+(s[i]-'0');
        m[ w<<depth ]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        sum=0; m.clear();  //初始化
        cin>>s;
        dfs(0,0,s.size()-1);

        int ans=0;
        for(map<long long,int> ::iterator it=m.begin();it!=m.end();it++)
            ans=max(it->second,ans);

        cout<<sum-ans<<endl;
    }
    return 0;
}
