#include<stdio.h>
#include<iostream>
#include<cctype>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> words;
map<string,int> m;
string repr(const string &s)
{
    string ans;
    ans=s;
    for(int i=0;i<s.length();i++)
        ans[i]=tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]=='#') break;
        words.push_back(s);
        string r;
        r=repr(s);
        if(!m.count(r))
            m[r]=0;
        m[r]++;
    }
    vector<string> v;
    for(int i=0;i<words.size();i++)
        if(m[repr(words[i])]==1)
            v.push_back(words[i]);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"\n";
    return 0;
}
/*ladder came tape soon leader acme RIDE lone Dreis peat
ScAlE orb eye Rides dealer NotE derail LaCeS drIed
noel dire Disk mace Rob dries
#*/
