#include<stdio.h>
#include<string.h>

const int maxn = 100;
char s[maxn];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int x = 0;
        while(n--)
        {
            scanf("%s",s);
            for(int i = 0; i < strlen(s); i++)
            {
                if(s[i] == '+')
                {
                    x++; break;
                }
                if(s[i] == '-')
                {
                    x--; break;
                }
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
