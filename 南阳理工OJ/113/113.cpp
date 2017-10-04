#include<stdio.h>
#include<string.h>

const int maxn = 1000 + 10;
char s[maxn];

int main()
{
    while(gets(s))
    {
        int len = strlen(s);
        int i = 0;
        while(i < len)
        {
            if(i < len - 2 && s[i] == 'y' && s[i + 1] == 'o' && s[i + 2] == 'u')
            {
                printf("we");
                i += 3;
            }
            else printf("%c",s[i++]);
        }
        printf("\n");
    }
    return 0;
}
