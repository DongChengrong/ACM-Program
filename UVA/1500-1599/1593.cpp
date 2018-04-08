#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxm=180+20;
const int maxv=1000+10;
map<int,int> m;
vector<string> v[maxv];
int row;

void print(string s,int len,char c)
{
    cout<<s;
    for(int i=0;i<len-s.length();i++)
        printf("%c",c);
}

void join(char *in,int r)
{
    int c=0;
    string s=""; string buf;
    s+=in;
    stringstream ss(s);
    while(ss>>buf)
    {
        c++;
        v[r].push_back(buf);
        if(!m.count(c)) m[c]=buf.length();
        else m[c]=max(m[c],(int)buf.length());
    }
}

int main()
{
    char s[maxm];
    row=0;
    while(gets(s))
    {
        row++;
        join(s,row);
    }
    for(int r=1;r<=row;r++)
    {
        for(int j=0;j<v[r].size();j++)
        {
            if(j==v[r].size()-1) { cout<<v[r][j]<<endl; }
            else print(v[r][j],m[j+1]+1,' ');
        }
    }
    return 0;
}
