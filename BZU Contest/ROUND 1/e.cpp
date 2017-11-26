#include<iostream>
#include<string>
#include<stdio.h>
#include<set>
#include<sstream>
using namespace std;

int main()
{
    string s;
    set<string> se;
    while(cin >> s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i]))
            {
                if('A' <= s[i] && s[i] <= 'Z')
                    s[i] -= ('A' -'a');
            }
            else s[i] = ' ';
        }

        string buf;
        stringstream ss(s);
        while(ss >> buf)
        {
            se.insert(buf);
        }
    }

    for(set<string> ::iterator it = se.begin(); it != se.end(); it++)
        cout << *it << endl;

    return 0;
}
