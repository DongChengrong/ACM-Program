#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

vector<int> v;
map<string,int> m1;
map<int,int> m2;
int key,ans;

void addNeed(int a)
{
    v.push_back(a);
}

int ID(string s)
{
    if(m1.count(s)) return m1[s];
    else { m1[s]=ans++;  return ans-1;}
}

bool removeNeed()
{
    int a;
    for(int i=0;i<v.size();i++)
    {
        a=v[i];
        if(m2.count(a)<=1) return false;
        m2[a]-=2;
    }
    return true;
}

bool judge()
{
    for(map<int,int>:: iterator it=m2.begin();it!=m2.end();it++)
        if(it->second%2) key++;
    if(key>2) return false;
    return true;
}

int main()
{
    string s1,s2;
    key=0; ans=1;
    while(cin>>s1>>s2)
    {
        int a,b;
        a=ID(s1); b=ID(s2);
        if(a==b) addNeed(a);
        else
        {
            if(!m2.count(a)) m2[a]=1;
            else m2[a]++;
            if(!m2.count(b)) m2[b]=1;
            else m2[b]++;
        }
    }
    if(!removeNeed()) printf("Impossible\n");
    if(judge()) printf("Possible\n");
    else printf("Impossible\n");
    return 1;
}
