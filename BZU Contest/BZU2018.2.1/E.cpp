#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        for(int i = 0; i < s1.length(); i++)
        {
            if(isupper(s1[i])) s1[i] -= 'A' - 'a';
            if(isupper(s2[i])) s2[i] -= 'A' - 'a';
        }
        if(s1 == s2) printf("0\n");
        if(s1 < s2) printf("-1\n");
        if(s1 > s2) printf("1\n");
    }
    return 0;
}
