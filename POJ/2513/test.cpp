#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int> m;
    string s1="sd";
    for(int i=0;i<5;i++)
    {
        if(!m.count(s1)) m[s1]=1;
        else m[s1]++;
    }
    cout<<m[s1]<<endl;
    return 0;
}
