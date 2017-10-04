#include<stdio.h>
#include<string.h>

const int maxn = 100;
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int i;
        for(i = 1; i < strlen(s); i++)
            if(s[i] != '0') break;

        if(i >= strlen(s)) printf("0\n");
        else printf("%s\n",s + i);
    }
    return 0;
}
