#include<stdio.h>
#include<string.h>

#define FOR(a,b) for(int i = a; i <= b; i++)
#define _FOR(b,a) for(int i = b; i >= a; i--)

typedef long long LL;

const int maxn = 100 + 10;
char s[maxn];

int main()
{
    while(scanf("%s",s) == 1)
    {
        if(strcmp(s,"0") == 0) break;
        int l = strlen(s);
        LL ans = 0;
        FOR(0,l - 1)
            ans += (s[i] - '0') * ((1 << l - i)-1);

        printf("%lld\n",ans);
    }
    return 0;
}
