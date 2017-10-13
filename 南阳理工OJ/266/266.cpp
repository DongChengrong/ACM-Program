#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;

const int maxn = 40 + 10;
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T); getchar();
    while(T--)
    {
        gets(s);
        int len = strlen(s);
        for(int i = len - 1; i >= 0; i--)
            if(isalpha(s[i])) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
