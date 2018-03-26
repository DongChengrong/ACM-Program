#include<stdio.h>
#include<string.h>

#define N 10000

int main()
{
    char s[N];
    bool flag = false;
    while(gets(s))
    {
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == '\"')
            {
                if(flag) printf("''");
                else printf("``");
                flag = !flag;
            }
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
