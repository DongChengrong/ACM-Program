#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;
char s[maxn];
char b[] = "hello";

int main()
{
    while(scanf("%s",&s) == 1)
    {
        int j = 0;
        for(int i = 0; i < strlen(s); i++)
        {
            if(j > 4) break;
            if(s[i] == b[j]) j++;
        }
        if(j > 4) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
