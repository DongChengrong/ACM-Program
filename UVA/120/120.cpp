#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int last;
vector<int> v;

int getTheMax()
{
    int key=0;
    for(int i=1;i<last;i++)
        if(v[i]>v[key]) key=i;
    return key;
}

int main()
{
    string s;
    while(!getline(cin,s))
    {
        cout<<s<<endl;
        int x;
        v.clear();
        stringstream ss(s);
        while(ss>>x) v.push_back(x);
        last=v.size();
    }
    return 0;
}
