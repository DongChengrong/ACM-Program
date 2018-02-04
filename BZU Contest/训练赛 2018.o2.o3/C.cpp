#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int base[]= {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int ok = 0;
        for(int i = 0 ; i < 14; i++)
            if(n % base[i] == 0)
            {
                ok = 1; break;
            }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
