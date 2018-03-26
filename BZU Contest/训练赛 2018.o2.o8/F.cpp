#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char s[maxn];

int main()
{
    while(scanf("%s",s) == 1)
    {
        int x = s[0] - '0';
        if(x != 9) s[0] = x < (9 - x) ? '0' + x : '0' + (9 - x);
        for(int i = 1; i < strlen(s); i++)
        {
            int x = s[i] - '0';
            s[i] = x < (9 - x) ? '0' + x : '0' + (9 - x);
        }
        printf("%s\n",s);
    }
    return 0;
}
