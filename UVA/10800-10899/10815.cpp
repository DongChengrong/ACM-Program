#include<iostream>
#include<string>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

string buf,s;
set<string> dic;

int main()
{
    while(cin>>s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>buf) dic.insert(buf);
    }
    for(set<string> ::iterator it=dic.begin();it!=dic.end();it++)
        cout<<*it<<endl;
    return 0;
}
