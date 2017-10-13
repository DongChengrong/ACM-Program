#include<stdio.h>
#include<string.h>
#include<cstring>
#include<ctype.h>
using namespace std;

const int maxn = 100 + 10;
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        for(int i = 0; i < strlen(s); i++)
        {
            if(islower(s[i])) printf("%c",toupper(s[i]));
            else printf("%c",tolower(s[i]));
        }
        printf("\n");
    }
    return 0;
}
