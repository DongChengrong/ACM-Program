#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;

map<string,int> m;

void init()
{
    m["one"] = 1; m["three"] = 3;
    m["two"] = 2; m["four"] = 4;
    m["five"] = 5; m["six"] = 6;
    m["seven"] = 7; m["eight"] = 8;
    m["nine"] = 9; m["zero"] = 0;
}

int main()
{
    init();
    string s;
    while(1)
    {
        int a = 0,b = 0;
        int flag = 0;
        while(cin >> s)
        {
            if(s == "=") break;
            if(s == "+")
            {
                flag = 1;
                continue;
            }
            if(!flag) a = a * 10 + m[s];
            else b = b * 10 + m[s];
        }
        if(!a && !b) break;
        printf("%d\n",a+b);
    }
    return 0;
}
