#include<stdio.h>
#include<string.h>

const int maxn = 1010 + 5;
int alp[26 + 5];
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(alp,0,sizeof(alp));
        scanf("%s",s);
        int max = 0;
        for(int i = 0; i < strlen(s); i++)
        {
            int j = s[i] - 'a';
            alp[j]++;
        }

        for(int i = 0; i< 26; i++)
            if(alp[max] < alp[i]) max = i;

        printf("%c\n",'a' + max);
    }
    return 0;
}
