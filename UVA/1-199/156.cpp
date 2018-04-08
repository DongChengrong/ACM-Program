#include<cstdio>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

set<string> S;
map<string,int> m;
string s;

void ss()
{
    for(int i=0;i<s.length();i++)
        s[i]=tolower(s[i]);
        sort(s.begin(),s.end());
}

int main()
{
    while(cin>>s && s[0]!='#')
    {
        S.insert(s);
        ss();
        if(m.count(s)==0) m[s]=0;
        else m[s]++;
    }
    for(set<string> ::iterator it=S.begin();it!=S.end();it++)
    {
        s=*it; ss();
        if(m[s]==0) cout<<*it<<endl;
    }
    return 0;
}
