#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char s[maxn];

int main()
{
    while(scanf("%s",s) == 1)
    {
        int ok = 1;
        int cnt = 1, pos = 1;
        while(pos < strlen(s))
        {
            if(s[pos] == s[pos - 1])
                cnt++;
            else
                cnt = 1;
            if(cnt >= 7)
            {
                ok = 0; break;
            }
            pos++;
        }
        if(!ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
