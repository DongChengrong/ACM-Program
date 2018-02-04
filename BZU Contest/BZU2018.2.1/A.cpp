#include<stdio.h>
#include<string.h>

const int maxn = 100 + 10;

char base[] = "aoyeui";
char s[maxn];

int main()
{
    while(scanf("%s",s) == 1)
    {
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] -= ('A' - 'a');
            for(int j = 0; j < strlen(base); j++)
                if(s[i] == base[j]) s[i] = '.';
        }
        for(int i = 0; i < strlen(s); i++)
            if(s[i] != '.')
                printf(".%c",s[i]);
        printf("\n");
    }
    return 0;
}
