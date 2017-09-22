#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

map<string,int> m;

void init()
{
    m["bowl"] = 1; m["fork"] = 1;
    m["knife"] = 1; m["chopsticks"] = 1;
}

int main()
{
    int n;

    init();

    while(cin >> n)
    {
        vector<string> v;
        string s;

        for(int i = 0; i < n; i++)
        {
            cin >> s;
            if(m.count(s)) v.push_back(s);
        }

        if(v.size()) cout << v[0];
        for(int i =1; i < v.size(); i++)
            cout <<" " << v[i];
        cout << endl;
    }
    return 0;
}
