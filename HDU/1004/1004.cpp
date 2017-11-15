#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N) == 1 && N)
    {
        map<string,int> m;
        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            if(m.count(s)==0) m[s] = 1;
            else m[s]++;
        }
        string s;
        int val = 0;
        map<string,int>::iterator it = m.begin();
        val = it->second;
        s = it->first;
        it++;
        while(it != m.end())
        {
            if(it->second > val)
            {
                val = it->second;
                s = it->first;
            }
            it++;
        }
        cout << s << endl;
    }
    return 0;
}
