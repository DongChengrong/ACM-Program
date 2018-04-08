#include<stdio.h>
#include<string.h>

#define N 100 + 10

char s[N];

int main()
{
    while(scanf("%s",s) == 1)
    {
        int i,j,k,cnt = 0;
        for(i = 0; i < strlen(s); i++)
            for(j = i + 1; j < strlen(s); j++)
                for(k = j + 1; k < strlen(s); k++)
                    if(s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                        cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}