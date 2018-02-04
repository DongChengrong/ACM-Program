#include<stdio.h>
#include<string.h>

const int maxn = 100 + 20;
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        if(strlen(s) > 10)
        {
            printf("%c%d%c\n",s[0],strlen(s) - 2, s[strlen(s) - 1]);
        }
        else
            printf("%s\n",s);
    }
    return 0;
}
