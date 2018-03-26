#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<map>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int n;
    while(cin >> n)
    {
        string name;
        map<string,int> names;
        while(n--)
        {
            cin >> name;
            if(names.count(name) == 0)
            {
                names[name] = 1;
                cout << "OK\n";
            }
            else
            {
                stringstream ss;
                ss << names[name];
                names[name]++;
                name += ss.str();
                names[name] = 1;
                cout << name << endl;
            }
        }
    }
    return 0;
}
