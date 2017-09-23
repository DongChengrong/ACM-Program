#include<stdio.h>
#include<string.h>

const int maxn = 100 + 10;
char s[maxn];

int main()
{
    while(scanf("%s",s) == 1)
    {
        int ok = 1;
        if(strlen(s) < 4 || s[0] != 'Y' || s[1] != 'A' || s[2] != 'K' || s[3] != 'I')
            ok = 0;
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
}
