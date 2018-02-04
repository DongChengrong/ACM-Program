#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char s1[maxn],s2[maxn];

int main()
{
    while(scanf("%s\n%s",s1,s2) == 2)
    {
        int ok = 1;
        int n = strlen(s1);
        if(strlen(s2) != n) {
            printf("NO\n");
            continue;
        }
        for(int i = 0; i < n; i++)
            if(s1[i] != s2[n - 1 - i])
                ok = 0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
