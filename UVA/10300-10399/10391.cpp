#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    string s;
    set<string> dir;
    while(cin>>s) dir.insert(s);
    for(set<string>::iterator it=dir.begin();it!=dir.end();it++)
    {
        s=*it;
        for(int i=0;i<s.length()-1;i++)
        {
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1,s.length()-(i+1));
            if(dir.find(s1)!=dir.end() && dir.find(s2)!=dir.end())
            { cout<<s<<endl; break; }
        }
    }
    return 0;
}
